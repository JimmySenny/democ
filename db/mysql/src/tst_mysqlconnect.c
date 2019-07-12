#include <stdio.h>
#include <string.h>
#include "mysql.h"

int
main(int argc, char** argv){
	int res;
	MYSQL connect;

	mysql_init(&connect);
	/* &MYSQL, host, user, passwd, dbname, 0, NULL, 0 */
	if(mysql_real_connect(&connect, "localhost", \
		"root", "password", "rmtdb", 0, NULL, CLIENT_FOUND_ROWS ) ){
		print("Connection success!");
		res = mysql_querry( &connect, "select * from tb_rmt_user");
		if(!res){
			;
		}else{
			print("res:%lu\n", (unsigned long)mysql_affected_rows(connect));
			
		}
	}else{
		print("Connection failed\n");
		if(mysql_errno(&connect)){
			print("error:[%d][%s]\n", mysql_error(&connect), mysql_error(&connect));
		}
	}


	return 0;
}

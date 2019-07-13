#include <stdio.h>
#include <string.h>
#include "mysql.h"

int
main(int argc, char** argv){
	int ret;
	MYSQL conn;
	MYSQL_RES *res = NULL;
	int num_rows = 0;

	mysql_init(&conn);
	/* mysql_real_connect(&conn, host, user, passwd, dbname, 0, NULL, 0) == NULL */
	if( mysql_real_connect(&conn, "127.0.0.1", "root", "password", "rmtdb", 0, NULL, CLIENT_FOUND_ROWS) ){
		printf("Connect success\n");
		ret = mysql_query(&conn, "select * from tb_rmt_user");
		printf("result [%d] \n", ret);
		if( !ret ){
			//printf("SELECT %ld rows\n", (unsigned long)mysql_affected_rows(&conn));
			res = mysql_store_result(&conn);
			if( res){
				num_rows = mysql_num_rows(res);
				printf("rows:[%d]\n", (int)num_rows);

				unsigned int num_fields = mysql_num_fields(res);
				printf("fields:[%d]\n", (int)num_fields);

				MYSQL_ROW row;
				char buffer[1024];
				while( row = mysql_fetch_row(res)){
					unsigned long * lengths = mysql_fetch_lengths(res);
					for( int i = 0; i < num_fields; i++){
						char *filed = row[i];
						unsigned int field_length = lengths[i];
						printf("column[%d], length[%d], data[%s]\n",\
							i, field_length, filed ? filed : "null");
					}
				}
			}
		}else{
			printf("SELECT ERROR %d:%s\n", mysql_errno(&conn), mysql_error(&conn));
		}
		mysql_close(&conn);
	}else{
		printf("Connect failed\n");
		if(mysql_errno(&conn)){
			printf("Connect ERROR %d:%s\n", mysql_errno(&conn), mysql_error(&conn));
		}
	}

	return 0;
}

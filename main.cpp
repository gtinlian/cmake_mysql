#include<mysql/mysql.h>
#include<stdio.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = "127.0.0.1";
    char *user = "root";
    char *password = "123456"; /* set me first */
    char *database = "mysql";
    char *query = "select user,host from user";
    int t, r;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
    } else {
        printf("Connected....\n");
    }
    t = mysql_query(conn, query);
    if (t) {
        printf("Error making query: %s\n", mysql_error(conn));
    } else {
        printf("Query made...\n");
        res = mysql_use_result(conn);
        if (res) {
            for (r = 0; r <= mysql_field_count(conn); r++) {
                row = mysql_fetch_row(res);
                if (row < 0) break;
                for (t = 0; t < mysql_num_fields(res); t++)
                    printf("%s", row[t]);
                printf("\n");
            }
        }
        mysql_free_result(res);
    }
    mysql_close(conn);
    return 0;
}
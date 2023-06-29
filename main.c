#include "bd.h"
int main()
{
    PGconn *conn;
    system("clear");

    // Estabelece a conexão com o banco de dados
    printf("Digite as informações de conexão (formato: \"dbname=postgres user=postgres password=123456 port=5432 host=localhost\"):\n");
    char conninfo[256];
    fgets(conninfo, sizeof(conninfo), stdin);
    conninfo[strcspn(conninfo, "\n")] = '\0'; // Remover o caractere de nova linha

    conn = PQconnectdb(conninfo);
    printf("Tentando se conectar ao banco de dados...\n");

    // Verifica se a conexão foi bem sucedida
    if (PQstatus(conn) != CONNECTION_OK)
    {
        printf("Falha na conexão: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return 1;
    }
    printf("Conexão bem sucedida!\n");

    while (1)
    {
        int option;
        printf("\nOpções:\n");
        printf("1. Criar tabela\n");
        printf("2. Inserir valores\n");
        printf("3. Mostrar suas tabelas\n");
        printf("4. Mostrar dados de uma tabela\n");
        printf("5. Remover dados de uma tabela\n");
        printf("6. Encerrar o programa\n");
        printf("Digite sua opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("clear");
            criar_tabela(conn);
            break;

        case 2:
            system("clear");
            inserir_valores(conn);
            break;

        case 3:
            system("clear");
            exibe_tabelas(conn);
            break;

        case 4:
            system("clear");
            exibe_dados_tabelas(conn);
            break;

        case 5:
            system("clear");
            remove_dados_tabela(conn);
            break;

        case 6:
            printf("Encerrando o programa...\n");
            PQfinish(conn);
            return 0;

        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}
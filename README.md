# pousada_matriz
Desenvolvimento de um sistema de gerenciamento de quartos de pousada, feito em C++ para a disciplina de Estrutura de Dados Orientada a Objetos, do curso de Sistemas de Informação do CIn, UFPE.

## Requisitos
- CMake (>= 3.15)
- Compilador C++ (GCC/Clang/MSVC)
- PostgreSQL (bibliotecas de desenvolvimento)
- libpqxx (biblioteca C++ para PostgreSQL)
- OpenSSL (para segurança nas conexões)

## Configuração
1. Crie um arquivo `.env` com sua string de conexão ao PostgreSQL:
   ```
   DATABASE_URL=postgresql://user:password@host:port/dbname
   ```

2. Execute o script SQL para criar as tabelas do banco de dados:
   ```bash
   psql "postgresql://user:password@host:port/dbname" -f sql/create_tables.sql
   ```

## Instruções de Build e Execução

1. Clone o repositório:
   ```bash
   git clone https://github.com/lucasmoraismt/pousada_matriz.git
   cd pousada_matriz
   ```

2. Configure o projeto:
   ```bash
   mkdir build && cd build
   cmake ..
   ```

3. Compile a aplicação:
   ```bash
   make
   ```

4. Execute a aplicação:
   ```bash
   ./
   ```


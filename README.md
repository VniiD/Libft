# Libft — 42SP

> *Este projeto foi criado como parte do currículo da 42SP por vde-alme*

---

## Descrição

Este projeto consiste no desenvolvimento de uma **biblioteca de sistema customizada em C**, contendo operações fundamentais de baixo nível. O objetivo principal é fazer a engenharia reversa de funções padrão da `libc`, além de:

- Gerenciar manualmente a memória RAM na Heap
- Realizar manipulações cirúrgicas de strings
- Implementar estruturas de dados dinâmicas (Listas Encadeadas)

O código interage diretamente com o comportamento do hardware, otimização de registradores e limites estritos de alocação, operando sob as restrições de formatação da **Norminette**.

---

## Inventário de Funções

### Parte 1 — Funções da Libc

Manipulação direta de células de memória e validação de bytes no barramento de dados.

**Classificação de Caracteres**
`ft_isalpha` · `ft_isdigit` · `ft_isalnum` · `ft_isascii` · `ft_isprint`

**Operações de Memória e Strings**
`ft_strlen` · `ft_memset` · `ft_bzero` · `ft_memcpy` · `ft_memmove` · `ft_strlcpy` · `ft_strlcat` · `ft_toupper` · `ft_tolower` · `ft_strchr` · `ft_strrchr` · `ft_strncmp` · `ft_memchr` · `ft_memcmp` · `ft_strnstr`

**Conversão de Tipos**
`ft_atoi` — descarta espaços de paginação, gerencia uma única polaridade de sinal explícita e aborta o loop imediatamente ao encontrar bytes ASCII não numéricos.

---

### Parte 2 — Funções Adicionais e Subsistemas de I/O

Alocação dinâmica na Heap e tratamento avançado de escrita via File Descriptors.

**Fatiamento e Junção**
`ft_substr` · `ft_strjoin` · `ft_strtrim` · `ft_split`

**Conversão Numérica**
`ft_itoa` — reverte um inteiro sinalizado em um array de bytes finalizado em nulo.

**Mapeamento Funcional**
`ft_strmapi` · `ft_striteri`

**Saída em File Descriptors**
`ft_putchar_fd` · `ft_putstr_fd` · `ft_putendl_fd` · `ft_putnbr_fd`
Suporte nativo para `1` (stdout) e `2` (stderr).

---

### Bônus — Estruturas de Lista Encadeada

Gerenciamento dinâmico utilizando indireção de ponteiros simples e duplos para interconectar nós em regiões não contíguas da Heap.

`ft_lstnew` · `ft_lstadd_front` · `ft_lstsize` · `ft_lstlast` · `ft_lstadd_back` · `ft_lstdelone` · `ft_lstclear` · `ft_lstiter` · `ft_lstmap`

---

## Decisões de Arquitetura

**Robustez contra `INT_MIN`**
`ft_putnbr_fd` utiliza uma variável de 64 bits (`long nb`) para absorver `-2147483648`, eliminando strings hardcoded e evitando Integer Overflow por Complemento de Dois.

**Rollback Automático em falhas de Heap**
`ft_lstmap` implementa tolerância zero a falhas: se um `malloc` falhar no meio da criação da nova lista, `ft_lstclear` é acionada imediatamente para liberar todos os nós anteriores — garantindo zero memory leaks.

**Aritmética de Ponteiros Direta**
Funções como `ft_atoi` e `ft_strlen` processam dados via `ptr++`, reduzindo overhead na stack frame e otimizando ciclos de clock.

**Segmentação de I/O por Canal**
O fluxo padrão (`stdout`) é isolado do fluxo de erro (`stderr`), com suporte nativo a sequências de escape ANSI (`\033[0;31m`) para formatação visual diretamente no driver de terminal.

**Conformidade Estrita com a Norminette (C89)**
- Proibição de operadores ternários
- Funções limitadas a 25 linhas
- Declarações de variáveis exclusivamente no topo dos blocos
- Código limpo e autodocumentado

---

## Compilação

A biblioteca é compilada com as flags estritas do GCC: `-Wall -Wextra -Werror`.

```bash
# Compilar a parte obrigatória → gera libft.a
make

# Remover arquivos objeto intermediários (.o)
make clean

# Remover objetos + binário final (libft.a)
make fclean

# Reset completo + recompilação do zero
make re
```

---

## Execução e Testes

Para validar a biblioteca contra o comportamento nativo do sistema operacional, linke seu arquivo de testes com o estático gerado:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o validador_42
```

---

## Referências

| Recurso | Descrição |
|---|---|
| ISO/IEC 9899 (C89/C99) | Especificação formal da linguagem C — base para conformidade com a Norminette |
| Linux Programmer's Manual | Comportamentos oficiais de `malloc(3)`, `free(3)` e `write(2)` |
| *The C Programming Language* — K&R | Referência para aritmética de ponteiros e manipulação de buffers |
| Especificações VT100/Xterm (ANSI) | Sequências de escape para diagnóstico visual nos testes de file descriptors |
| Tabela ASCII | Mapeamento de bytes para conversões de caixa e filtragem de espaços em `ft_atoi` |

---

## Uso de Inteligência Artificial

Um modelo de IA foi utilizado como orientador arquitetural e validador de escopo, com cooperação estritamente delimitada a:

- **Análise de memória e hardware** — mapeamento das restrições do `INT_MIN` e dos caracteres de controle ASCII (9–13) na `ft_atoi`
- **Modelagem de segurança da Heap** — lógica do rollback emergencial da `ft_lstmap`
- **Cenários de teste** — construção de rotinas de validação cruzada com máscaras ANSI para contrastar outputs da Libft com o comportamento padrão do kernel
- **Auditoria da Norminette** — revisão preventiva de conformidade estrutural (limite de 25 linhas, declarações no topo, ausência de ternários)

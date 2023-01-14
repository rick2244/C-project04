#include "project04.h"
int main(int argc, char **argv) {

    struct scan_table_st scan_table; // table of tokens
    struct parse_table_st parse_table; // table of parse nodes
    struct parse_node_st *parse_tree; // tree (pointers only) of parse nodes

    char input[SCAN_INPUT_LEN];
    int len;
    char *expression;
    int base = 10;
	int width = 32;

	for(int i = 1; i < argc; i++){
		if(!strncmp(argv[i], "-b", 2)){
			base = string_to_int(argv[i + 1], 10);
			i++;
		}else if(!strncmp(argv[i], "-e", 2)){
			expression = argv[i + 1];
			i++;
		}else if(!strncmp(argv[i], "-w", 2)){
			width = string_to_int(argv[i+1], 10);
			i++;
		}
	}
    strncpy(input, expression, SCAN_INPUT_LEN);
    len = strnlen(input, SCAN_INPUT_LEN);

    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input, len);

    parse_table_init(&parse_table);
    parse_tree = parse_program(&scan_table);
    int res = eval_tree(parse_tree);
    const char* val;
    int_to_string(res, val, base, width);
    
        
    return 0;
}


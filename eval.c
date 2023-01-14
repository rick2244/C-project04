// parse.c - parsing and parse tree construction

#include "project04.h"

int eval_tree(struct parse_node_st *node){
	if(node->type == EX_INTVAL){
		return node->intval.value;
	}else if(node->type == EX_OPER2){
		int left = eval_tree(node->oper2.left);
		int right = eval_tree(node->oper2.right);
		if(node->oper2.oper == OP_PLUS){
			return left + right;
		}else if(node->oper2.oper == OP_MINUS){
			return left - right;
		}else if(node->oper2.oper == OP_MULT){
			return left * right;
		}else if(node->oper2.oper == OP_DIV){
			return left / right;
		}else if(node->oper2.oper == OP_FOR){
			return left >> right;
		}else if(node->oper2.oper == OP_BACK){
			return left << right;
		}else if(node->oper2.oper == OP_AND){
			int combine = left & right;
			return combine;	
		}else if(node->oper2.oper == OP_OR){
			return left | right;
		}else if(node->oper2.oper == OP_EXOR){
			return left ^ right;	
		}
	}else if(node->type == EX_OPER1){
		unsigned int val = eval_tree(node->oper1.operand);
		if(node->oper1.oper == OP_MINUS){
			return val * (-1);
		}if(node->oper1.oper == OP_NOT){
			return ~(val);
		}
	}
}

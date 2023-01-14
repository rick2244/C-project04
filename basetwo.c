#include <stdio.h>
#include <string.h>
#include "project04.h"
const char* int_to_string(int num, const char* val, int base, int width){
	char res[64];
	char res3[64];
	char res5[64];
	int i = 0;
	int c;
	if(base == 10){
		int negpos = num;
		if(num > 0){
			while(num > 0){
				res[i++] = num%10 + 48;
				num/=10;
			}
			c = 0;
		}else if(num < 0){
			res[0] = '-';
			num = num * (-1);
			while(num > 0){
				res[++i] = num%10 + 48;
				num/=10;
			}
			i++;
			c = 1;
		}
		res[i] = '\0';
		char* res2 = res;
		int len = strlen(res2);
		if(negpos > 0){
			for(int b = len -1; b >= 0;b--){
				res3[c++] = res2[b];
			}	
		}else if(negpos < 0){
			res3[0] = '-';
			for(int b = len -1; b >= 1;b--){
				res3[c++] = res2[b];
			}
		}
		res3[c] = '\0';
		val = res3;
	}else if(base == 2){
		res3[0] = '0';
		res3[1] = 'b';
		if(num > 0){
				while(num > 0){
			res[i++] = num%2 + 48;
			num/=2;	
		}	
		}
		while(num > 0){
			res[i++] = num%2 + 48;
			num/=2;	
		}
		res[i] = '\0';
		char* res2 = res;
		int len = strlen(res2);
		int c = 2;
		int zero = width - i;
		for(int d = 0; d < zero; d++){
			res3[c++] = '0';
		}
		for(int b = len -1; b >= 0; b--){
			res3[c++] = res2[b];
		}
		res3[c] = '\0';
		val = res3;
	}else if(base == 16){
		res3[0] = '0';
		res3[1] = 'x';
		int negpos = num;
		if(num < 0){
			num*=-1;
		}
		while(num > 0){
			char c;
			int remain = num%16;
			if(remain >= 10 && remain <= 15){
				c = remain + 55;
			}else{
				c = remain + 48;
			}
			res[i++] = c;
			num/=16;	
		}
		res[i] = '\0';
		char* res2 = res;
		int len = strlen(res2);
		int c = 2;
		int length;
		if(width == 32){
			length = 8;
		}else if(width == 16){
			length = 4;
		}else if(width == 8){
			length = 2;
		}
		int zero = length - i;
		for(int d = 0; d < zero; d++){
			res3[c++] = '0';
		}
		for(int b = len -1; b >= 0; b--){
			res3[c++] = res2[b];
		}
		res3[c] = '\0';
		char* res4 = res3;
		val = res3;
		if(negpos < 0){
			res5[0] = '0';
			res5[1] = 'x';
			negpos+=1;
			int end = strlen(res4)-1;
			for(int i = 2;i <= end - 1; i++){
				if(res4[i] == '0'){
					res5[i] = 'F';
				}else if(res4[i] == '1'){
					res5[i] = 'E';
				}
				else{
					res5[i] = res4[i];
				}
			}
			res5[end] = res4[end];
			res5[end+1] = '\0';
			val = res5;
		}
	}
	printf("%s\n", val);
	return val;
}

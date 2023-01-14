#include "project04.h"

int string_to_int(char *string, int base) {
    int len = strlen(string);
    int num = 0;
    int PV = 1;
    if(base == 10){
    	for(int i = len-1; i >=0; i--){
    		num += (string[i] - 48) * PV;
    		PV*=base;
    		
    	}	
    }
    else if(base == 2 || base == 16){
    	for(int i = len -1; i >=0; i--){
    		if(string[i] == 'a' || string[i] == 'A'){
    			num += 10 * PV;
    		}else if(string[i] == 'b' || string[i] == 'B'){
    			num += 11 * PV;
    		}else if(string[i] == 'c' || string[i] == 'C'){
    		    num += 12 * PV;
    		}else if(string[i] == 'd' || string[i] == 'D'){
    		    num += 13 * PV;
    		}else if(string[i] == 'e' || string[i] == 'E'){
    		    num += 14 * PV;
    		}else if(string[i] == 'f' || string[i] == 'F'){
    		    num += 15 * PV;
    		}else{
    			num += (string[i] - 48) * PV;
    		}
    		PV*= base;
    	}
    }
    return num;
}


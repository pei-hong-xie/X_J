#include "Meun.h"
#include "Btree.h"

int main() {
	while (1) {
		
		if (Flag_1 == 0) {
			Meun_Flag_1();
		}
		else if (Flag_1 == 1) {
			Meun_Flag_2(Flag);
		}
		else if (Flag_1 == 2) {
			Meun_Flag_3(Flag);
		}
	}
	
	/*Meun_Flag_1();
	Meun_Flag_2(Flag);
	Meun_Flag_3(Flag);*/
	

	return 0;

}
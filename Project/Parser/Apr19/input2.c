/*
 * input2.c
 *
 * This program performs extensive testing on loop-statements 
 *
 * By Huizhe Li, Master Student, Dartmouth College
 */

int main(void){
	int layer1, layer2, layer3, layer4;

	/* nested loops and condition-stmts */
	while(layer1){
		layer1;		/* in layer 1 */
		if(1)continue;
		for(;;++i){	/* see place-holder "bozo" for empty for_header expr */
			layer2;		/*in layer 2 */
			if(1)
				continue;
			else
				 break;
			while(bigger > smaller){
				layer3;		/* in layer 3 */
				switch(bozo){	/* a switch-stmt */
				case 1:	i++;
					i--;
					
					break;
				case 2: break;
				case 3: print "yeah~~~";
					break;
				default:while(1){layer4;}	/* in layer 4 */
					break;
				}

			}
		}
	}		

	/* empty statements 
	 * may cause segmentation fault if not handled properly
	 */
	if(1)
		if(1)
			if(1)
				/* do nothing */;
			else
				/* dangling else */;
	
}



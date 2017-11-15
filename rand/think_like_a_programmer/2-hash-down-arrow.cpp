///////////////////////////////////////////////////////////
// Exercise 2-1. from "Thinking Like A Programmmer"	 //
// 							 //
// Create the function generating the following pattern: //
// 							 //
// ########						 //
//  ######						 //
//   ####						//   ######   //
//    ####    //
//     ##     //
////////////////
void generate_arrow(int width) {
    int current_width = width;
    while(current_width > 0) {
	generate_centered_row(width, current_width);
	current_width -= 2;
    }
}


int main() {
    ios_base::sync_with_stdio(0);                
    generate_arrow(8);
}

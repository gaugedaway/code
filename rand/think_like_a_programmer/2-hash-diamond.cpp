///////////////////////////////////////////////////////////
// exercise 2-2. from "Thinking Like A Programmmer"	 //
// 							 //
// Create the function generating the following pattern: //
// 							 //
//    ##						 //
//   ####						 //
//  ######						 //
// ########						 //
//  ######						 //
//   ####						 //
//    ##						 //
///////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;


///////////////////////////////////////////////////////////////////////////
// |---- full_width -----|						 //
//   |- current_width -|						 //
// 									 //
//   ###################						 //
// 									 //
// Warning: works properly only when full_width - current_width is even. //
///////////////////////////////////////////////////////////////////////////
void generate_centered_row(int full_width, int current_width) {
    int left_align = (full_width - current_width) / 2;
    for(int i = 0; i < left_align; i++) cout << ' ';
    for(int i = 0; i < current_width; i++) cout << '#';
    cout << '\n';
}


////////////////
// |- width-| //
// 	      //
// ########## //
//  ########  //
//   ######   //
//    ####    //
//     ##     //
////////////////
void generate_arrow_down(int width, int init_width = -1) {
    if(init_width == -1) init_width = width;
    int current_width = init_width;
    while(current_width > 0) {
	generate_centered_row(width, current_width);
	current_width -= 2;
    }
}


////////////////
// |- width-| //
//     ##     //
//    ####    //
//   ######   //
//  ########  //
// ########## //
////////////////
void generate_arrow_up(int width, int last_width = -1) {
    if(last_width == -1) last_width = width;
    int current_width;
    if(width%2 == 0) current_width = 2;
    else current_width = 1;
    while(current_width <= last_width) {
	generate_centered_row(width, current_width);
        current_width += 2;
    }
}


////////////////
// |- width-| //
//     ##     //
//    ####    //
//   ######   //
//  ########  //
// ########## //
//  ########  //
//   ######   //
//    ####    //
//     ##     //
////////////////
void generate_diamond(int width) {
    generate_arrow_up(width);
    generate_arrow_down(width, width - 2);
}


int main() {
    ios_base::sync_with_stdio(0);                
    generate_diamond(8);
}

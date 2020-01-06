#include "view.h"

View::View(Store& store) : _store{store} { }

std::string View::main_menu() 
{

	return R"(

	<span font="Sans Bold 18">Welcome to C1325 MavMart</span><sup>TM</sup>
	
<span font="Arial bold 12"> <u>Products</u>          <u>Orders</u>            <u>File I/O</u>      <u>Utility</u> </span>
(1) <i>Add Product </i>              (4) <i>Place Order</i>            (6) <i>Save</i>              (9) <span fgcolor='#00ff00'><i>Help</i></span>
(2) <i>List all products </i>       (5) <i>List all orders</i>         (7) <i>Load</i>              (0) <i>Exit</i>

)";	

}

std::string View::help() 
{
	return R"(
	
<span font="Arial Bold 12">Welcome to the <span underline="double">C1325 MavMart</span> help menu!</span>

<span font="Sans">This program manages an on-line store named MavMart, which sells generic products.</span>
	
<b>Under Product</b>   Select <i>"Add Product"</i> to add a product to the store. You'll be asked to enter a product name and price. Select <i>"List all Products"</i> to see all the products sold by the store.

<b>Under Order</b>   Select <i>"Add Order"</i> if you'd like to place an order. You will be asked to enter an email address followed by the index of the product you would like to order and the quantity of that product you would like. Select <i>"List All Orders"</i> to see all current orders. 
  
<b>Under File</b>   Select <i>"Load"</i> to load a predefined selection of products to the store. Select <i>"Save"< to write and save all data to the specified file in the current folder, or exit the program.
 
	
<span size="larger">Thank you for choosing C1325 MavMart!</span>	
	)";
}
	
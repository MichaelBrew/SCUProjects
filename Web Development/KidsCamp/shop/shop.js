var loggedIn = 0;

var catalog = [
	{itemname:"Backpack", price:9.99, quantity:0, size:"none"},
	{itemname:"Waterbottle", price:4.99, quantity:0, size:"none"},
	{itemname:"Keychain", price:3.99, quantity:0, size:"none"}, 
	{itemname:"Boy Tee", price:14.99, quantity:0, size:"none"},
	{itemname:"Girl Tee", price:14.99, quantity:0, size:"none"},
	{itemname:"Umbrella", price:7.99, quantity:0, size:"none"}
	];
	
function getItemPrice(item) {
	for (var i = 0; i < catalog.length; ++i){
		if (catalog[i].itemname == item) {// item found
				return catalog[i].price;
		}		
	}
	return 0;
}

function updateCart(item) {
	var orderString = "<b>Check out when finished shopping!</b>";
	var n = document.getElementById(item).length;
	var total = 0;
	
	/* Check for boy size (shirts) */
	if (item == "Boy Tee") {
		for(i=0;i<document.getElementById("bsize").length;i++) {
			if(document.getElementById("bsize").options[i].selected)
				catalog[3].size = document.getElementById("bsize").options[i].value;
		}
	}
	
	/* Check for girl size (shirts) */
	if (item == "Girl Tee") {
		for(i=0;i<document.getElementById("gsize").length;i++) {
			if(document.getElementById("gsize").options[i].selected)
				catalog[4].size = document.getElementById("gsize").options[i].value;
		}
	}
	
	/* Get quantity and price of item */
	for(i=0;i<n;i++) {
		if(document.getElementById(item).options[i].selected) {
			var quantity = document.getElementById(item).options[i].value;
			var price = getItemPrice(item);
		}
	}
	
	/* Set quantity in cart */
	for (i=0;i<catalog.length;i++){
		if (catalog[i].itemname == item) { //item found
			catalog[i].quantity = quantity;
			break;
		}	
	}
	
	/* Create orderString with proper HTML to display cart */
	orderString += "<p>";
	for(i=0;i<catalog.length;i++) {
		if(catalog[i].quantity > 0){ //if ordered
			if(catalog[i].size != "none") { //if shirt
				orderString += catalog[i].size + " " + catalog[i].itemname + " x" + catalog[i].quantity + " at $" + catalog[i].quantity*catalog[i].price + "<br>";
			}
			else
				orderString += catalog[i].itemname + " x" + catalog[i].quantity + " at $" + catalog[i].quantity*catalog[i].price + "<br>";
			total += catalog[i].quantity*catalog[i].price;
		}
	}
	
	if(loggedIn == 1) {
		total = (total * 0.85);
		total = total.toFixed(2);
	}
	
	orderString += "</p>";
	orderString += "<b>Your Total: $" + total;
	
	document.getElementById("cart").innerHTML = orderString;
}

/* Function to clear cart and reset variables */
function checkout() {
	var str = "<h2>Thanks for shopping with us!</h2>";
	document.getElementById("cart").innerHTML = str;
	
	elements = document.getElementsByTagName("select")
	for(var i=0; i < elements.length ; i++){
		elements[i].selectedIndex = 0;
	}
	
	for(i=0;i<catalog.length;i++) {
		catalog[i].quantity = 0;
		catalog[i].size = "none";
	}

	document.getElementById('cardName1').value = ""
	document.getElementById('cardNo1').value = "";
	document.getElementById('expire1').value = "";
	document.getElementById('csv1').value = "";
}
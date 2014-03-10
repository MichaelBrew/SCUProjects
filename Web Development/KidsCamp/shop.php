<!DOCTYPE html>
<?php
	session_start();
?>
<html lang="en">
<head>
	<meta charset="utf-8"/>
	<title>Shop</title>

	<!-- Linking CSS -->
	<link rel="stylesheet" type="text/css" href="mystyles.css">
	<link href='http://fonts.googleapis.com/css?family=Wellfleet|Neucha' rel='stylesheet' type='text/css'>

	<script src="myscripts.js"></script>
	<script src="shop/shop.js" type="text/javascript"> </script>
	<script src="jquery.js" type="text/javascript"></script>
	<script src="jquery.validate.js" type="text/javascript"></script>
	<script src="additional-methods.js" type="text/javaScript"></script>
	
	<?php
		if(!isset($_SESSION['visitedShop'])) {
			$_SESSION['visitedShop'] = 1;
			echo "<script>visitedShop = 0;</script>";
		}
		else {
			echo "<script>visitedShop = 1;</script>";
		}
		
		if ($_SESSION['loggedIn'] == 1) {
			echo "<script>loggedIn = 1;</script>";
		}

	?>
	
	
	<script type="text/javascript">
		if (loggedIn == 1 && visitedShop == 0)
			alert("You get a 15% discount for being a member! Your total will be adjusted accordingly.");
	</script>
	
	<style>
		#shop {
			border: 2px solid black;
			border-radius: 5px;
			padding: 10px;
			width: 55%;
			height: 550px;
			
			float: left;
		}
		
		#cart {
			border: 2px solid black;
			border-radius: 5px;
			padding: 10px;
			
			width: 40%;
			height: 250px;
			float: right;
		}
		
		#creditpayment1 {
			margin-top: 20px;
			float:right;
		}
	</style>
</head>
<body> 
	<!-- Copy & paste this to each page -->
	<div id="window">
		<div id="loggedin">
			<div style="text-align:right; margin-bottom:5px;">
			   <?php if(isset($_SESSION['user'])) echo "<b>Welcome, " . $_SESSION['user'] . "!</b>"; ?>
			    <form action="logout.php" method="post">
				<input type="submit" value="Logout" style="padding:5px; float:right; margin-top:15px;"/>
			  </form>
			</div>
		</div>
		<div id="login">
			<div style="text-align:right; margin-bottom:5px;">Already registered? Login below</div>
			<form method="post" action="processLogin.php">
				<label>Email:</label> <input type="text" name="loginemail"><br>
				<label>Password:</label><input type="password" name="loginpass"><br><br>
				<input type="submit" value="Login">
			</form>
		</div>
			<?php
		    if($_SESSION['loggedIn'] == 1) {
				echo '<script language="javascript">document.getElementById("login").style.visibility = "hidden";</script>';
			}
			else {
				echo '<script language="javascript">document.getElementById("loggedin").style.visibility = "hidden";</script>';
			}
		  ?>

		<div id="title"> <img src="logo.jpg" alt="Kid's Camp Logo" width="100" height="100" style="position:relative; top: 20px; right:10px;">Kids Camp Inc.</div>

		<nav id="navBar">
			<ul>
				<li><a href="homepage.php">Home</a></li>
				<li><a href="register.php">Register</a></li>
				<li><a href="reviews.php">Reviews</a></li>
				<li><a href="shop.php">Shop</a></li>
				<li><a href="stats.php">Stats</a></li>
			</ul>
		</nav>
		
		<!-- End Copy/Paste -->
		 <div class="content">
			<h1 style="margin-top:0"><br>Welcome to our Shop!</h1>
			
			<div id="shop">
				<b>Make your selections from our catalog below. Your cart will be updated on the right.</b>
				
				<table id="catalog" cellspacing="20" style="text-align:center;">
					<tr>
						<td> <img src="shop/backpack.jpg" alt="Backpack" height="150" width="150"> <br>
							Kids Camp Backpack <br> $9.99 <br> <select id="Backpack" onChange="updateCart('Backpack')">
																<option value="0" selected>0</option>
																<option value="1">1</option>
																<option value="2">2</option>
																<option value="3">3</option> </select>
						</td>
						<td> <img src="shop/waterbottle.png" alt="Waterbottle" height="150" width="150"> <br>
							Kid's Camp Waterbottle <br> $4.99 <br> <select id="Waterbottle" onChange="updateCart('Waterbottle')">
																<option value="0" selected>0</option>
																<option value="1">1</option>
																<option value="2">2</option>
																<option value="3">3</option> </select>
						</td>
						<td> <img src="shop/keychain.jpg" alt="Keychain" height="150" width="150"> <br>
							Souvenir Camp Keychain <br> $3.99 <br> <select id="Keychain" onChange="updateCart('Keychain')">
																<option value="0" selected>0</option>
																<option value="1">1</option>
																<option value="2">2</option>
																<option value="3">3</option> </select>
						
						</td>
					</tr>
					<tr>
						<td> <img src="shop/boystee.jpg" alt="Boy's Tee" height="150" width="150"> <br>
							Boy's T-Shirt <br> $14.99 <br> <select id="bsize">
																<option value="Small" selected>Small</option>
																<option value="Medium">Medium</option>
																<option value="Large">Large</option> </select>
																
																<select id="Boy Tee" onChange="updateCart('Boy Tee')">
																<option value="0" selected>0</option>
																<option value="1">1</option>
																<option value="2">2</option>
																<option value="3">3</option> </select>
						
						</td>
						<td> <img src="shop/girlstee.jpg" alt="Girl's Tee" height="150" width="150"> <br>
							Girl's T-Shirt <br> $14.99 <br> <select id="gsize">
																<option value="Small" selected>Small</option>
																<option value="Medium">Medium</option>
																<option value="Large">Large</option> </select>
																
																<select id="Girl Tee" onChange="updateCart('Girl Tee')">
																<option value="0" selected>0</option>
																<option value="1">1</option>
																<option value="2">2</option>
																<option value="3">3</option> </select>
						
						</td>
						<td> <img src="shop/umbrella.jpg" alt="Umbrella" height="150" width="150"> <br>
							Kid's Camp Umbrella <br> $7.99 <br> <select id="Umbrella" onChange="updateCart('Umbrella')">
																<option value="0" selected>0</option>
																<option value="1">1</option>
																<option value="2">2</option>
																<option value="3">3</option> </select>
						</td>
					</tr>
				</table>
				
			</div>
		
			<div id="cart">
				<b> Your cart will appear here as you make selections. Checkout when ready! </b>
			</div>

			<div id="creditpayment1">Enter credit info here: <br />
					<form id="creditpayment2">
						<label>Cardholder Name:</label> <input type="text" name="cardName1" id="cardName1"/><br/>
						<label>Card Number:</label> <input type="text" name="cardNo1" id="cardNo1"/><br/>
						<label>Exp:</label> <input type="text" name="expire1" id="expire1" style="width: 50px;"/>
						<label>CSV:</label> <input type="text" name="csv1" id="csv1" style="width: 50px;"/>
					</form>
						<button style="float:right;" onClick="checkout()">Checkout</button>
			</div>
			<script type="text/javascript">
							jQuery("#creditpayment2").validate({
								rules: {
								    cardName1: {
									    required: true
								    },
								    cardNo1: {
									    required: true
								    },
								    expire1: {
									    required: true,
									    minlength:5,
									    maxlength:5
								    },
								    csv1: {
									    required: true,
									    minlength: 3,
									    maxlength: 3
								    }
							    },
							    messages: {
								    cardName1: "Please enter name",
								    cardNo1: "Please enter valid #",
								    expire1: "Please enter valid date",
								    csv1: "Please enter valid CSV"
							    },
							    success: function(element) {
							    $(element).addClass("valid");
						    }
						    });
						</script>
		<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
	<footer>
		Created by Michael Brew and Bryant Larsen <br>Contact at <i>mbrew@scu.edu</i> or <i>blarsen@scu.edu</i>
	</footer>
		</div>
	
	</div>
	  
	<br>
	
</body>
</html>

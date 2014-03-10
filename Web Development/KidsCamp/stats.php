<!DOCTYPE html>
<?php
  session_start();
?>
<html lang="en">
<head>
	<meta charset="utf-8"/>
	<title>Statistics</title>

	<!-- Linking CSS -->
	<link rel="stylesheet" type="text/css" href="mystyles.css">
	<link href='http://fonts.googleapis.com/css?family=Wellfleet|Neucha' rel='stylesheet' type='text/css'>

	<!-- Linking JavaScript -->
	<script src="myscripts.js"></script>

	<!-- Implementing graph -->
	<script language="javascript" type="text/javascript" src="jquery.js"></script>
	<script language="javascript" type="text/javascript" src="jquery.flot.js"></script>
	<script type="text/javascript">implementGraph();</script>

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
	  
		<div class="content">
		<h1 style="text-align:center; margin-top:0;"><br>Enrollment Statistics</h1>
		<h3 style="text-align:center;">Check out our history of camp attendance!</h3>
			<div id="graph" style="width:600px; height:300px; margin-left:auto; margin-right:auto;"></div>
		<br><br><br><br><br><br><br><br><footer>Created by Michael Brew and Bryant Larsen <br>Contact at <i>mbrew@scu.edu</i> or <i>blarsen@scu.edu</i></footer>
		</div>

		
	</div>
	
</body>
</html>
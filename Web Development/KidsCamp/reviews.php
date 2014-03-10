<!DOCTYPE html>
<?php
	session_start();
?>
<html lang="en">
<head>
	<meta charset="utf-8"/>
	<title>Reviews</title>

	<!-- Linking CSS -->
	<link rel="stylesheet" type="text/css" href="mystyles.css">
	<link href='http://fonts.googleapis.com/css?family=Wellfleet|Neucha' rel='stylesheet' type='text/css'>

	<script src="myscripts.js"></script>

	<style>
		#comments {
			border: 2px solid black;
			border-radius: 5px;
			
			margin-left: 50px;
			width: 50%;
			height: 350px;
			padding: 10px;
		}
		
		p {
			margin-left: 30px;
			width: 50%;
		}
	</style>
</head>
<body> 
	
		
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
		<h1 style="padding-left:10px; margin-top:0px;"><br>Reviews & Suggestions</h1>
		
		<div id="comments">
			<h2>Leave your own review:</h2>

			<form method="post" action="processReview.php" id="submitReviewArea">
				<label>Name:</label> <input type="text" name="name" /><br />
				<label>Camp Attended:</label> <input type="text" name="camp"/><br />
				<label>Comments:</label> <br/><textarea cols="50" rows="10" name="comments">Enter some stuff here.</textarea> <br>
				<input type="submit" value="Submit" style=" float:right; padding:5px;" />
			</form>
		
		</div>
	
		<br>
		<hr>
		<h2>See Past Comments Below</h2>
		
		<?php
			error_reporting(E_ALL);
			ini_set('display_errors', '1');
		
			$con = mysqli_connect('dbserver.engr.scu.edu', 'blarsen', '00000887511', 'sdb_blarsen');
			if(!$con) {
				die("Could not connect: " . mysql_error());
			}
			
			$result = mysqli_query($con, "SELECT * FROM Reviews");

			# Query the database and populate the reviews section
			while($row = mysqli_fetch_array($result)) {
				echo "<p><b>" . $row['ReviewerName'] . "</b> (" . $row['CommentDate'] . ")<br>";
				echo "<i>" . $row['CampAttended'] . "</i><br><br>";
				echo $row['Comments'] . "</p>";
			}
		?>

		<br/>
		<footer>
		Created by Michael Brew and Bryant Larsen <br>Contact at <i>mbrew@scu.edu</i> or <i>blarsen@scu.edu</i>
	</footer>
  </div>
		
	</div>
</body>
</html>
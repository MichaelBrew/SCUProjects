<!DOCTYPE html>
<?php
session_start();
?>
<html lang="en">
<head>
	<meta charset="utf-8"/>
	<title>Welcome to Kids Camp!</title>

	<!-- Linking CSS -->
	<link rel="stylesheet" type="text/css" href="mystyles.css">
	<link href='http://fonts.googleapis.com/css?family=Wellfleet|Neucha' rel='stylesheet' type='text/css'>

	<script src="myscripts.js"></script>
	<script src="http://maps.google.com/maps/api/js?sensor=false" 
          type="text/javascript"></script>
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

			#Login fail, alert user
			if($_SESSION['loginFail'] == 1) {
				echo "<script type='text/javascript'> 
					 alert('Login failed, incorrect email or password');
				      </script>";
				$_SESSION['loginFail'] = 0;
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

		<!-- End copy & paste -->
		<div class="content">
			<div id="locations">
				<h1 style="position:relative;">Locations</h1>

				<div id="map" style="width: 550px; height: 400px; float:left; 
				border:2px black solid; position:relative; top:10px;"></div>
				<script type="text/javascript">implementMap();</script>	
			</div>

			<div id="activity">
				<h2>What We Do</h2>
				<p style="margin-bottom:20px;">
				   Our camps encompass a wide range of outdoor and computer based activities split into 2 weeks. The first week of camp
				    is focused on outdoor recreation where campers will play many sports including soccer, football, tennis, basketball, baseball,
				    and more! The first week will also focus on other outdoor camping activities such as hiking, rock climbing, campfire building,
				    and we'll even take a scheduled trip to the beach. On the final day of the week we host a kickball tournament where campers are split into teams of 10 and compete to become
				    Kids Camp kickball champions! As you can see, we at Kid's Camp Inc are devoted to providing your child with a multitide of
				    educational camp programs over the summer.
				</p>  

				<img src="football.svg" width="200" height="200" style="float:left; margin:20px;"/>
				<p style="margin-top:50px;">
					Our computer week introduces campers to the fundamentals of programming, like using variables, having objects, Hello World, etc.
					We invite professors from the host universities to come talk to the kids about why programming is important, and how they can
					continue learning after the camp duration. By the end of the week each child will be able to to build a simple, browser based game
					which they can show off to all their friends and family! Our camp staff are highly qualified and can't wait to teach your children!
					A complete list of topics taught: HTML 5, CSS, JavaScript, PHP, light photoshop for design, and working with web servers.
					
				</p>
				<h3 style="clear:left; margin-top:10px;">Our site's services</h3>
				<p>Through this website you'll be able to view the locations of each camp through the google map, check out the schedule on the registration page, register your child, leave a review about 
				  your camp experience, buy merchandise from our shop, and view our enrollment statistics! If you have any comments, questions, or suggestions please contact us
				  at the email addresses listed at the bottom of the screen.</p>

				<table id="requirements">
					<tr>
						<td style="font-size:30px">Requirements</td>
					</tr>
					<tr>
						<td>Between 10 and 14 years old</td>
						<td>Interest in learning about computers</td>
					</tr>
					<tr>
						<td>Able to travel to Bay Area</td>
						
						<td>Able to attend at least a full week</td>
					</tr>
				</table>
			</div>
			<footer style="display:inline-block">
			      <br><br><br>Created by Michael Brew and Bryant Larsen <br>Contact at <i>mbrew@scu.edu</i> or <i>blarsen@scu.edu</i>
		      </footer>
		</div>
	</div>

	
</body>
</html>
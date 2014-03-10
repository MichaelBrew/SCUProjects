<!DOCTYPE html>
<?php
	session_start();
?>
<html lang="en">
<head>
	<meta charset="utf-8"/>
	<title>Register</title>

	<!-- Linking CSS -->
	<link rel="stylesheet" type="text/css" href="mystyles.css">
	<link href='http://fonts.googleapis.com/css?family=Wellfleet|Neucha' rel='stylesheet' type='text/css'>

	<!-- Linking JavaScript -->
	
	<script src="myscripts.js"></script>

	<script src="jquery.js" type="text/javascript"></script>
	<script src="jquery.validate.js" type="text/javascript"></script>
	<script src="additional-methods.js" type="text/javaScript"></script>
	
</head>
<body> 
	<?php
	if($_SESSION['registered'] == 1) {
		//echo '<script language="javascript">alert("You have successfully registered!")</script>';
		echo '<div id="ok" style="position:absolute; left:50%;
							top:150px; text-align:center;
							width:400px; height:200px; z-index:5;">
				<div style="position:relative; left:-50%; border:2px solid black; border-radius:5px;
							background-color:rgba(220,240,245,0.9);">
					<p style="margin:10px;"><b>Congratulations, you have successfully registered! You can now login in the
					top right corner using your email address and password<b></p>
					<button type="button" onclick="removeConfirmation()" style="margin-bottom:20px;">
					Got it!</button>

				</div>
			  </div>';

		$_SESSION['registered'] = 0;
	}
	else if($_SESSION['registered'] == -1) {
		echo '<div id="ok" style="position:absolute; left:50%;
							top:150px; text-align:center;
							width:400px; height:200px; z-index:5;">
				<div style="position:relative; left:-50%; border:2px solid black; border-radius:5px;
							background-color:rgba(220,240,245,0.9);">
					<p style="margin:5px;">There was an error processing your registration</p>
					<button type="button" onclick="removeConfirmation()" style="margin-bottom:20px;">
					Retry</button>

				</div>
			  </div>';

		$_SESSION['registered'] = 0;
	}
	?>
	
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
				echo "<script>var loggedIn = 1;</script>";
			}
			else {
				echo '<script language="javascript">document.getElementById("loggedin").style.visibility = "hidden";</script>';
				echo "<script>var loggedIn = 0;</script>";
			}
			
	?>

		<div id="title">
			<img src="logo.jpg" alt="Kid's Camp Logo" width="100" height="100" style="
			position:relative; top: 20px; right:10px;">Kids Camp Inc.</div>

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
			<div id="registrationWrapper">
				<div id="schedule">
					<h1>2014 Schedule</h1>
					<ul>
						<li style="list-style-type:none; font-weight:bold;">Santa Clara University 6/2 - 6/15</li>
						<ul>
							<li>Computer Week 6/2 - 6/8</li>
							<li>Outdoors Week 6/9 - 6/15</li>
						</ul>

						<li style="list-style-type:none; font-weight:bold;">Stanford University 7/7 - 7/20</li>
						<ul>
							<li>Computer Week 7/7 - 7/13</li>
							<li>Outdoors Week 7/14 - 7/20</li>
						</ul>

						<li style="list-style-type:none; font-weight:bold;">San Jose State University 8/4 - 8/17</li>
						<ul>
							<li>Computer Week 8/4 - 8/10</li>
							<li>Outdoors Week 8/11 - 8/17</li>
						</ul>
					</ul>
					<img src="computer.svg" width="350" height="350" style="float:left; position:relative;"/>
				</div>
				
				  
				<div id="registrationArea">
					<h1>Register</h1>
					<b>Use your email and password to login after registration</b><br>
					<b>If you've previously registered, login to receive 15% off the shop and 10% off future registrations!</b><br><br>

					<form method="post" action="processRegister.php" id="registrationForm" name="registrationForm">
						<label>Child's full name:</label> <input type="text" name="childname"><br>
						<label>Parent's full name:</label> <input type="text" name="parentname"><br>
						<label>Child's age:</label> <input type="text" name="age"><br>
						<label>Contact email:</label> <input type="text" name="email"><br>
						<label>Contact phone number:</label> <input type="text" name="phonenumber"><br>
						<label>Grade level:</label> <input type="text" name="grade"><br>
						<label>Current school:</label> <input type="text" name="school"><br>
						<label>Desired camp:</label> 
							<select name="desiredcamp">
								<option value="SCU">Santa Clara University</option>
								<option value="stanford">Stanford University</option>
								<option value="SJSU">San Jose State University</option>
							</select><br><br><br><br>
						<input type="checkbox" style="margin-left:215px;" name="weekone" value="week1" id="week1" onclick="updateTotal(loggedIn)"/>Week 1 <br>
						<input type="checkbox" style="margin-left:215px; margin-bottom:5px;" name="weektwo" value="week2" id="week2" onclick="updateTotal(loggedIn)"/>Week 2<br>
						<label>Special instructions?</label> <input type="text" name="special"><br>
						<label>Login Password:</label> <input type="password" name="password"><br>
					    
						<script type="text/javascript">
							jQuery("#registrationForm").validate({
								rules: {
									childname: {
									    required: true
									},
									parentname: {
									    required: true
									},
									age: {
									    required: true,
									    min:10,
									    max:14
									},
									email: {
									    required: true,
									    email: true
									},
								    phonenumber: {
									    required: true,
									    phoneUS: true
								    },
								    grade: {
									    required: true,
									    min: 4,
									    max: 10
								    },
								    school: "required",
								    password: "required",
								    cardName: {
									    required: true
								    },
								    cardNo: {
									    required: true
								    },
								    exp: {
									    required: true,
									    minlength:5,
									    maxlength:5
								    },
								    svc: {
									    required: true,
									    minlength: 3,
									    maxlength: 3
								    }
							    },
							    messages: {
								    childname: "Please enter child's name",
								    parentname: "Please enter parent's name",
								    age: {
									    required: "Please enter age",
									    min: "Must be aged 10 to 14",
									    max: "Must be aged 10 to 14"
								    },
								    email: "Please enter valid email",
								    phonenumber: "Please enter valid number",
								    grade: {
									    required: "Please enter grade level",
									    min: "Must be 4th to 10th grade",
									    max: "Must be 4th to 10th grade"
								    },
								    school: "Please enter current school",
								    password: "Please enter a password",
								    cardName: "Please enter name",
								    cardNo: "Please enter valid #",
								    exp: "Please enter valid date",
								    svc: "Please enter valid CSV"
							    },
							    success: function(element) {
							    $(element).addClass("valid");
						    }
						    });
						</script>
						<br><b>Total:<span id="totalRegistrationPrice"></span></b><br><br>

						<div id="creditpayment"><div style="font-size:20px; margin-bottom:5px;">Enter credit info</div> <br />
							<label>Cardholder Name:</label> <input type="text" name="cardName"/><br/>
							<label>Card Number:</label> <input type="text" name="cardNo"/><br/>
							<label>Exp (mm/yy):</label> <input type="text" name="exp" style="width: 50px;"/><br>
							<label>CSV:</label> <input type="text" name="svc" style="width: 50px;"/><br>
						</div>


						<input type="submit" value="Submit" style="float:right; 
						margin-right:30px; margin-top:15px;">
					</form>
				
				</div>
				
			</div>
			<footer style="display:inline-block">
			Created by Michael Brew and Bryant Larsen <br>Contact at <i>mbrew@scu.edu</i> or <i>blarsen@scu.edu</i>
			</footer>
		</div>
	</div>
	
</body>
</html>

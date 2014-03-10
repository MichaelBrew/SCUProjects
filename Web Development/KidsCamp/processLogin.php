<?php
	session_start();
	header('location:homepage.php');
	
error_reporting(E_ALL);
			ini_set('display_errors', '1');

	$username = $_POST['loginemail'];
	$password = $_POST['loginpass'];
	echo $username; echo $password;

	$link = mysqli_connect('dbserver.engr.scu.edu', 'blarsen', '00000887511', 'sdb_blarsen');


	if(!$link) {
		die("Could not connect: " . mysql_error());
	}
	echo 'Connected successfully!';

	$result = mysqli_query($link, "SELECT ParentName, Email, Password FROM UserInfo");
	
	# Search for user in database
	while($row = mysqli_fetch_array($result)) {
		if ($username == $row['Email'] && $password == $row['Password']) {
			$_SESSION['user'] = $row['ParentName'];
			$_SESSION['loggedIn'] = 1;
			exit();
		}
	}
	
	# Login Failed
	$_SESSION['loggedIn'] = 0;
	$_SESSION['loginFail'] = 1;

?>
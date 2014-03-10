<?php
	session_start();
	header('location:reviews.php');

	error_reporting(E_ALL);
	ini_set('display_errors', '1');

	$name = (isset($_POST['name']) ? $_POST['name'] : null);
	$camp = (isset($_POST['camp']) ? $_POST['camp'] : null);
	$comments = (isset($_POST['comments']) ? $_POST['comments'] : null);
	$date = date("m/d/Y");

	$link = mysqli_connect('dbserver.engr.scu.edu', 'blarsen', '00000887511', 'sdb_blarsen');

	if(!$link) {
		die("Could not connect: " . mysql_error());
	}
	echo 'Connected successfully!';

	$query = "INSERT INTO Reviews (ReviewerName, CampAttended, Comments, CommentDate)
				VALUES 
				('{$name}', '{$camp}', '{$comments}', '{$date}')";

	if(!mysqli_query($link, $query))
	{
		die('Error: ' . mysqli_error($link));
	}

?>
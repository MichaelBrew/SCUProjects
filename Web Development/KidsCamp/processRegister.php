<?php
	session_start();
	header('location:register.php');

	error_reporting(E_ALL);
	ini_set('display_errors', '1');

	$childName = ($_POST['childname']);
	$parentName = ($_POST['parentname']);
	$age = ($_POST['age']);
	$email = ($_POST['email']);
	$phone = ($_POST['phonenumber']);
	$grade = ($_POST['grade']);
	$school = ($_POST['school']);
	$camp = ($_POST['desiredcamp']);
	$specialInstructions = ($_POST['special']);
	$password = ($_POST['password']);

	$week1 = ($_POST['weekone']);
	$week2 = ($_POST['weektwo']);
	$weekAttendance = 0;
	if(isset($week1)) {
	    if(isset($week2)) $weekAttendance = 3;
	    else $weekAttendance = 1;
	}
	else if(isset($week2)) $weekAttendance = 2;

	$link = mysqli_connect('dbserver.engr.scu.edu', 'blarsen', '00000887511', 'sdb_blarsen');

	if(!$link) {
		die("Could not connect: " . mysql_error());
	}
	echo 'Connected successfully!';

	$query = "INSERT INTO UserInfo (ChildName, ParentName, Age, Email, Phone,
						Grade, School, Camp, Instructions, WeekAttendance, Password)
				VALUES 
				('{$childName}', '{$parentName}', '{$age}', '{$email}', '{$phone}',
					'{$grade}', '{$school}', '{$camp}', '{$specialInstructions}', '{$weekAttendance}', '{$password}')";

	if(!mysqli_query($link, $query))
	{
		$_SESSION['registered'] = -1;
		die('Error: ' . mysql_error($link));
	}

	$_SESSION['registered'] = 1;

	mysql_close($link);
?>
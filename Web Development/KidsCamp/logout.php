<?php
	header('location:homepage.php');
	session_start();

	session_destroy();
	$_SESSION = array();
?>
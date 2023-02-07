<?php
//Creates new record as per request
    //Connect to database
    // $servername = "us-cdbr-east-06.cleardb.net";		//example = localhost or 192.168.0.0
    // $username = "b1a5a43416daaa";		//example = root
    // $password = "c00249cd07ca62d";	
    // $dbname = "heroku_5e3abbc608c2126";
    $servername = "192.168.43.101";		//example = localhost or 192.168.0.0
    $username = "pasindu";		//example = root
    $password = "1234";	
    $dbname = "eleccare";


    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Database Connection failed: " . $conn->connect_error);
    }

    //Get current date and time
    date_default_timezone_set('Asia/Colombo');
    $d = date("Y-m-d");
    $t = date("H:i:s");

    if(!empty($_POST['voltage']) && !empty($_POST['current']) && !empty($_POST['power']) && !empty($_POST['energy']) && !empty($_POST['frequency']) && !empty($_POST['pf']) )
  {
                $voltage = $_POST['voltage'];
                $current = $_POST['current'];
                $power = $_POST['power'];
                $energy = $_POST['energy'];
                $frequency = $_POST['frequency'];
                $pf = $_POST['pf'];
                $account_no = 144444;
	    $sql = "INSERT INTO elec_usage (account_no,voltage,current,power,energy,frequency,pf,date, time) VALUES ( '".$account_no."','".$voltage."','". $current."','".$power."','".$energy."','".$frequency."','".$pf."','".$d."', '".$t."')"; //nodemcu_ldr_table = Youre_table_name

		if ($conn->query($sql) === TRUE) {
		    echo "OK";
		} else {
		    echo "Error: " . $sql . "<br>" . $conn->error;
		}
	}


	$conn->close();
?>
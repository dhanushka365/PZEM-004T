<?php
$server="localhost";
$username="pasindu";//THE DEFAULT USERNAME OF THE DATABASE
$password="1234";
$dbname="relay";
$con=mysqli_connect($server,$username,$password,$dbname) or die("unable to connect");
$relay_id = $_GET["Relay_ID"];
$sql="SELECT Status from relay where Relay_ID = $relay_id";//WE ARE TRYING TO GET THE NAME OF THE STUDENT BY ENTERING THE RANK
$result = mysqli_query($con,$sql);
if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {    
      echo  $row["Status"];
}
}
?>
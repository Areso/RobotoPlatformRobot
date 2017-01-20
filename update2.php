<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
</head>
<body>
<?php
echo $_POST["speed"];
echo "<br>";
echo $_POST["angle"];
$speed = $_POST["speed"];
$angle = $_POST["angle"];
include("connection.php");
try {
    $conn = new PDO("mysql: host=$servername;port=$port;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "UPDATE maintable SET speed=".$speed.", wheel_pos=".$angle.", xy_axis_cam=0, z_axis_cam=0, cam_power=1, action=0, battery_status=0 WHERE id=1";
echo $sql;
    $conn->exec($sql);
    
    unset($username);
    unset($password);
    
    echo "New record created successfully";
}
catch(PDOException $e) {
    echo $sql . "<br>" . $e->getMessage();
}

  $conn = null;
?>
</body>
</html> 

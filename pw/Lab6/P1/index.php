<?php
  include 'connect.php';
?>
<!DOCTYPE html>
<html>
<head>
	<title>P1</title>
</head>
<body>
	<p>
		<?php
			$sql = "SELECT * FROM Statii LIMIT 2";
			$result=mysqli_query($conn,$sql);
			if(mysqli_num_rows($result) > 0){
				while($row = mysqli_fetch_assoc($result))
				{
					echo "<p>";
					echo $row[ 'plecare' ];
					echo "</p>";
				}
			}else
			{
				alert("Daaaa");
			}
		?>
	</p>

</body>
</html>
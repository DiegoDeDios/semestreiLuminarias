<?php
 include 'dbc.php';
 $output = '';
 $sql = "SELECT * FROM lampStatus ORDER BY idStatus DESC";
 $result = mysqli_query($conn, $sql);
 echo '
 <script type="text/javascript">
		$(document).ready(function(){
			$(".led").click(function(){
				var status = $(this).attr("id");
				switch (status) {
					case "Status":
						$.get("http://192.168.43.123/!1!);
						document.getElementById("LightStatus").innerHTML = "Light Status: ON";
						break;
					case "0":
						$.get("http://172.16.101.131/!0!");
						document.getElementById("LightStatus").innerHTML = "Light Status: OFF";
						break;
					default:
						break;
				}
			});
		});
	</script>';
 $output .= '
      <div class="table-responsive">
           <table class="table table-bordered">
                <tr>
                     <th width="10%">ID</th>
                     <th width="20%">MAC</th>
                     <th width="20%">IP</th>
                     <th width="10%">VOLTAJE</th>
                     <th width="10%">ESTADO</th>
                     <th width="40%">FECHA de Act</th>
                </tr>';
 if(mysqli_num_rows($result) > 0)
 {
      while($row = mysqli_fetch_array($result))
      {
           $output .= '
                <tr>
                     <td class="ID" data-id0="'.$row["idStatus"].'"contenteditable>'.$row["idStatus"].'</td>
                     <td class="MAC" data-id1="'.$row["MAC"].'" contenteditable>'.$row["MAC"].'</td>
                     <td class="IP" data-id2="'.$row["IP"].'" contenteditable>'.$row["IP"].'</td>
                     <td class="Volt" data-id3="'.$row["Voltaje"].'" contenteditable>'.$row["Voltaje"].'</td>
                     <td class="Status" data-id4="'.$row["Estado"].'"><button id="Status" class="led">'.$row["Estado"].'</button></td>
                     <td class="stDate" data-id5="'.$row["stDate"].'">'.$row["stDate"].'</td>
                     <td><button type="button" name="delete_btn" data-id3="'.$row["idStatus"].'" class="btn btn-xs btn-danger btn_delete">x</button></td>
                </tr>
           ';
      }
      $output .= '
           <tr>
                <td id="ID" contenteditable></td>
                <td id="MAC" contenteditable></td>
                <td id="IP" contenteditable></td>
                <td id="Volt" contenteditable></td>
                <td id="Status" contenteditable></td>
                <td></td>
                <td><button type="button" name="btn_add" id="btn_add" class="btn btn-xs btn-success">+</button></td>
           </tr>
      ';
 }
 else
 {
      $output .= '<tr>
                          <td colspan="4">Data not Found</td>
                     </tr>';
 }
 $output .= '</table>
      </div>';
 echo $output;
 ?>

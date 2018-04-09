<?php
include 'dbc.php';
$output='';
$sql= 'SELECT * FROM Lampara ORDER BY LamparaN';
$result= mysqli_query($conn, $sql);
$output.='<div class = "table-responsive">
            <table class = "table table-bordered">
            <tr>
              <th>IP</th>
              <th>Numero</th>
              <th>Status</th>
            </tr>
';
 if(mysqli_num_rows($result) > 0){
   while($row = mysqli_fetch_array($result)) //Minetras haya datos...
   {
    $output .= '
     <tr>
      <td>'.$row["IP"].'</td>
      <td class = "numeroLamp" data-id1="'.$row["LamparaN"].'" contenteditable>'.$row["Estatus"].'</td>
      <td><button name ="btDel" id="btn_delete" data-id2="'.$row["IP"].'"></button></td>
     </tr>
    ';  //Imprime en cada fila los atributos de la entidad Lampara
   }
 }
 else{


 }
$output.='</table>
</div>';
?>

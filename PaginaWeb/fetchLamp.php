<?php
include 'dbc.php'; //Documento que hace la conexion de la BD
$output = '';
if(isset($_POST["query"]))
{
 $search = mysqli_real_escape_string($conn, $_POST["query"]); // El metodo evita posibles inyecciones de SQL
 $query = "
  SELECT * FROM Lampara
  WHERE IP LIKE '%".$search."%'
  OR LamparaN LIKE '%".$search."%'
  OR Estatus LIKE '%".$search."%'
 "; //El query habla por si solo. Ana Delia estaria decepcionado si no sabes que hace
 $result = mysqli_query($conn, $query);
 if(mysqli_num_rows($result) > 0) //Si el numero de filas sea mayor a cero....
 {
  $output .= "
   <div class='table-responsive'>
   <table id='tableAl' class='table table-bordered table-striped' style='width:100%'><tr>
   <thead>
     <tr>
      <th>IP</th>
      <th>Numero Lampara</th>
      <th>Estatus</th>
     </tr>
  "; //Se hace echo de codigo de html con los datos y se crea una tabla
  while($row = mysqli_fetch_array($result)) //Minetras haya datos...
  {
   $output .= '
    <tr>
     <td>'.$row["IP"].'</td>
     <td>'.$row["LamparaN"].'</td>
     <td>'.$row["Estatus"].'</td>
    </tr>
   ';  //Imprime en cada fila los atributos de la entidad Lampara
  }
  echo $output;
  echo "</thead>
        <tbody></tbody>
        </table>";
 }
 else
 {
  echo 'Data Not Found';
 }
}


?>

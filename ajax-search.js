$(document).ready(function(){

 load_data();

 function load_data(query)
 {
  $.ajax({
   url:"fetchLamp.php", //Pagina a la que se hace referencia 
   method:"POST",
   data:{query:query},
   success:function(data)
   {
    $('#result').html(data);   //Busca el tag de result e imprime los datos en esa parte del documento
   }
  });
 }
 $('#search_text').keyup(function(){
  var search = $(this).val();
  if(search != '')
  {
   load_data(search);
  }
  else
  {
   load_data();
  }
 });
});

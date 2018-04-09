<!DOCTYPE html>
<html>
<head>
  <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>
  <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js'></script>
  <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>
  <script src='../jQueryTabledit/jquery.tabledit.js'></script>
  <link rel='stylesheet' type='text/css' href='style.css'>
  <script src="https://code.jquery.com/jquery-1.12.4.min.js"></script>
  <script>
  $(document).ready(function(){

   load_data();

   function load_data(query)
   {
    $.ajax({
     url:"fetchLamp.php",
     method:"POST",
     data:{query:query},
     success:function(data)
     {
      $('#result').html(data);
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
  </script>
</head>
<body>
  <div id="Cap" class="tab-pane fade in active">
    <div class="col-lg-9">
      <div class ="listAl">
        <div class="center">
    </div>
        <div class="col-lg-12">
          <div class="text-center">
            <br>
            <div class="form-group">
             <div class="input-group">
              <span class="input-group-addon">Busqueda</span>
              <input type="text" name="search_text" id="search_text" placeholder="Buscar Lampara" class="form-control" />
             </div>
            </div>
       </br>
         <div id="result"></div>
          </div>
        </div>
      </div>
    </div>
  </div>
</body>
</html>

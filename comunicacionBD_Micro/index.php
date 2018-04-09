<html>
<head>
  <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>
  <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js'></script>
  <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>
  <script src='ajax-search.js'></script>
</head>
<body>
  <div class="Menu">
    <div class="col-sm-12">  <!-- Contenedor del navbar -->
      <nav class= "navbar navbar-inverse">
        <div class= "container-fluid">
          <div class="navbar-header">
              <a class="navbar-brand" href="#">Administracion</a>
          </div>
          <ul class="nav navbar-nav">
            <li class="active"><a data-toggle="tab" href="#home" href="#">Home</a></li>
                  <li><a data-toggle="tab" href="#busqueda" href="#">Consulta</a></li>
                  <li><a data-toggle="tab" href="#add"href="#">Agregar</a></li>
                  <li><a data-toggle="tab" href="#au" href = "#">Sobre Nosotros</a></li>
          </ul>
        </div>
      </nav>
    </div>
  </div>
  <div class="Contenido">
  <div class="col-sm-12">
    <div class="tab-content">
      <!-- Pestaña de inicio. Incluye un carrusel de bootstrap-->
      <div id="home" class="tab-pane fade in active">
        <div id="myCarousel" class="carousel slide" data-ride="carousel">
          <ol class="carousel-indicators">
            <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
            <li data-target="#myCarousel" data-slide-to="1"></li>
            <li data-target="#myCarousel" data-slide-to="2"></li>
          </ol>
          <div class="carousel-inner">
            <div class="item active">
              <img src="img/light1.jpeg">
              <div class="carousel-caption">
                <h3>Por noches iluminadas</h3>
                <p>Luminarias automatizadas</p>
              </div>
            </div>

            <div class="item">
              <img src="img/light2.jpg">
              <div class="carousel-caption">
                <h3>Consulta de sistemas activos</h3>
                <p>Detección de fallas</p>
              </div>
            </div>

            <div class="item">
              <img src="img/light3.jpg">
              <div class="carousel-caption">
                <h3>Busqueda y localizacion</h3>
                <p>Encontrar fallas en determinada area</p>
              </div>
            </div>
          </div>
          <a class="left carousel-control" href="#myCarousel" data-slide="prev">
            <span class="glyphicon glyphicon-chevron-left"></span>
            <span class="sr-only">Previous</span>
          </a>
          <a class="right carousel-control" href="#myCarousel" data-slide="next">
            <span class="glyphicon glyphicon-chevron-right"></span>
            <span class="sr-only">Next</span>
          </a>
            </div>
            </div>
      <!-- La pestaña de busqueda hace referencia al script de ajax y hace busquedas asincronas en la BD -->
      <div id="busqueda" class="tab-pane fade">
        <div class="form-group">
        <input type="text" name="search_text" id="search_text" placeholder="Buscar Lampara" class="form-control" />
        </div>
         <div id="result"></div>
      </div>
      <!-- La parte de edicion de tablas se hace en un script de php aparte-->
      <div id="add" class="tab-pane fade">
        <div id="live-data">

        </div>
      </div>
      <div id="au" class="tab-pane fade">
        <p>Introducir pendejadas sobre nosotros aqui</p>
      </div>
      </div>
  </div>
</div>
</body>
</html>

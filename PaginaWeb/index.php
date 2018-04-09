<html>
<head>

  <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>
  <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js'></script>
  <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>
  <script src='ajax-search.js'></script>


    <!--Temporal para uso de Bootstrap local-->

    <meta charset="utf-8">
		<title>Luminarias Zapopan</title>

    <!--
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta name="description" content="">

		<link href="bootstrap/css/bootstrap.min.css" rel="stylesheet">
		<link href="bootstrap/css/bootstrap-responsive.min.css" rel="stylesheet">
		<link href="themes/css/bootstrappage.css" rel="stylesheet"/>

		<link href="themes/css/flexslider.css" rel="stylesheet"/>
		<link href="themes/css/main.css" rel="stylesheet"/>

		<script src="themes/js/jquery-1.7.2.min.js"></script>
		<script src="bootstrap/js/bootstrap.min.js"></script>
		<script src="themes/js/superfish.js"></script>
		<script src="themes/js/jquery.scrolltotop.js"></script>

    -->

    <!--Fin de importaciones locales-->

</head>
<body>
  <div class="Menu">
    <div class="col-sm-12">  <!-- Contenedor del navbar -->
      <nav class= "navbar navbar-inverse">
        <div class= "container-fluid">
          <div class="navbar-header">
              <a class="navbar-brand" href="#">Administración</a>
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
              <img src="img/light1.jpeg" style="height:90%" width=100%/>
              <div class="carousel-caption">
                <h3>Por noches iluminadas:</h3>
                <p>Somos pioneros en desarrollo de luminarias automatizadas.</p>
              </div>
            </div>

            <div class="item">
              <img src="img/light2.jpg" style="height:90%" width=100%/>
              <div class="carousel-caption">
                <h3>Fácil consulta de sistemas activos:</h3>
                <p>Gracias a nuestro sistema de detección de fallas.</p>
              </div>
            </div>

            <div class="item">
              <img src="img/light3.jpg" style="height:90%" width=100%/>
              <div class="carousel-caption">
                <h3>Búsqueda y localizacion:</h3>
                <p>Conoce el estado y lugar de cada luminaria.</p>
              </div>
            </div>
          </div>
          <a class="left carousel-control" href="#myCarousel" data-slide="prev">
            <span class="glyphicon glyphicon-chevron-left"></span>
            <span class="sr-only"></span>
          </a>
          <a class="right carousel-control" href="#myCarousel" data-slide="next">
            <span class="glyphicon glyphicon-chevron-right"></span>
            <span class="sr-only"></span>
          </a>
            </div>
            </div>
      <!-- La pestaña de busqueda hace referencia al script de ajax y hace busquedas asincronas en la BD -->
      <div id="busqueda" class="tab-pane fade">
        <div class="form-group">
        <input type="text" name="search_text" id="search_text" placeholder="¿Qué lámpara buscas?" class="form-control" />
        </div>
         <div id="result"></div>
      </div>
      <!-- La parte de edicion de tablas se hace en un script de php aparte-->
      <div id="add" class="tab-pane fade">
        <?php
          include 'editTables.php';
        ?>
      </div>
      <div id="au" class="tab-pane fade">
        <p><img src="https://memecreator.org/static/images/memes/4750570.jpg" style="height:90%" /></p>
      </div>
      </div>
  </div>
</div>
</body>
</html>

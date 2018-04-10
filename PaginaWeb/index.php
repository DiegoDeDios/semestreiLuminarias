<html>
<head>

  <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>
  <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js'></script>
  <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>
  <script src='ajax-search.js'></script>

  <meta charset="utf-8">
  <title>Luminarias Zapopan</title>


    <!--Temporal para uso de Bootstrap local-->

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
          <div class="container-fluid">
            <div class="row content">
              <div class="col-sm-4 sidenav">
                <h4><small>Odio a mi equipo</small></h4>
                <hr>
                <p><img src="https://memecreator.org/static/images/memes/4750570.jpg" style="height:90%" /></p>
              </div>

              <div class="col-sm-8">
                <h4><small>Acerca de nosotros</small></h4>
                <hr>
                <h2>Edwing "El Negro" Ulin</h2>
                <h5> Encargado de robar cables. </h5>
                <h5><span class="label label-danger">Nigga</span> <span class="label label-primary">Watermelon</span></h5><br>
                <div class="col-sm-3 sidenav">
                  <p><img src="https://frutascharito.es/187-large_default/sandia-1-2-unid.jpg" style="height:auto" width=100%/></p>
                </div>
                <div class="col-sm-9 sidenav">
                    <p class="blog">Este ser humano proveniente de África es un ladrón por naturaleza. Cuando no lo ves robando, lo ves comiendo
                    sandía y tomando Kool-Aid. Existe la ligera posibilidad de que si lo encuentras en su tiempo libre, te
                    reconozca como una presa fácil, por lo que es recomendable traer algo con lo cual puedas protegerte de un
                    inminente robo. 8/10 volveríamos a meterlo al equipo.</p>
                    <br><br><br><br><br><br><br><br><br><br><br>
                </div>

                <hr>

                <h2>Diego "El Gay" Martínez</h2>
                <h5> Encargado de tener demasiados aparatos inútiles que resultan siendo útiles.</h5>
                <h5><span class="label label-danger">Gay</span> <span class="label label-primary">Geek</span></h5><br>
                <div class="col-sm-3 sidenav">
                  <p><img src="https://rlv.zcache.com/7_stripes_rainbow_gay_pride_flag_square_paper_coaster-r814768c7037647488d69eedbd81d3613_z6z50_260.jpg?rlvnet=1&rvtype=content&square_it=fit" style="height:auto" width=100%/></p>
                </div>
                <div class="col-sm-9 sidenav">
                    <p class="blog">Precaución: la homosexualidad al igual que la lepra es altamente contagiosa. Diego es uno de esos seres
                    vivos que se ven atraídos a aquellos que son tanto de su misma especie, como de su mismo sexo. Esto resulta en la necesidad
                    del equipo de caminar pegados a la pared por los pasillos y la omisión de bromas y chistes que hagan referencia a la homosexualidad,
                    pues nunca podremos estar seguros de cuándo Diego puede tomar una oportunidad y hacernos suyo.</p>
                    <br><br><br><br><br><br><br><br><br><br>
                  <br><br>
                </div>

                <hr>

                <h2>Luis "El Güicho" Flores</h2>
                <h5> Encargado de todo lo que tenga que ver con el microcontrolador.</h5>
                <h5><span class="label label-danger">Gay</span> <span class="label label-primary">Fluent C</span></h5><br>
                <div class="col-sm-3 sidenav">
                  <p><img src="https://i.pinimg.com/originals/0a/e9/b9/0ae9b901ec1463f991c0cfe433990a23.jpg" style="height:auto" width=100%/></p>
                </div>
                <div class="col-sm-9 sidenav">
                    <p class="blog">Tenemos nuestras sospechas acerca de que este miembro del equipo también batea para tercera base, pero hasta
                    no confirmar la teoría lo seguiremos tratando como a un ser humano normal. Para lograr una comunicación efectiva con Luis, es
                    importante y absolutamente necesario primero establecer una petición para entablar una conversación. Una vez que el usuario
                    reciba una confirmación por parte de Wicho, antes de mandar un mensaje es necesario utilizar el comando AT+IPSEND para lograr
                    que el mensaje llegue a su destinatario</p>
                    <p class="blog">Nota: Favor de no introducir alcohol a su sistema, puede tornarse un poco agresivo e impredecible.</p>
                    <br><br><br><br><br><br><br>
                  <br><br><br>
                </div>

                <hr>

                <h2>Miguel "El Mike" Triana</h2>
                <h5> Encargado de saber sobre carros.</h5>
                <h5><span class="label label-danger">Petrolhead</span> <span class="label label-primary">Stupid af</span></h5><br>
                <div class="col-sm-3 sidenav">
                  <p><img src="https://oupsie.info/wp-content/uploads/2017/10/minivan-with-rims-importkillers-new-ride-offroad-minivan-hummer-forums-news.jpg" style="height:auto" width=100%/></p>
                </div>
                <div class="col-sm-9 sidenav">
                    <p class="blog">Este peculiar individuo pasa su mayoría del día pensando, hablando, o viendo videos sobre carros. Fuera de eso,
                    parece que fue nombrado jefe de la división de chistes estúpidos, pues es lo único que hace cuando no se dedica a los carros.
                    A veces hace cosas de provecho, pero arruina sus momentos de gloria con su casi inexistente sentido de seriedad. Sin embargo, el
                    hecho de que siempre estuviera en el campus nos daba la seguridad de que siempre estaba ahí para cualquier trabajo que necesitáramos
                    realizar.</p>
                    <br><br><br><br><br><br><br><br>
                </div>

                <hr>

                <h2>Jorge "El Pietra" Pietra Santa</h2>
                <h5> Ex-encargado de redes. Actual encargado de la GUI.</h5>
                <h5><span class="label label-danger">Fatass</span> <span class="label label-primary">Useless</span></h5><br>
                <div class="col-sm-3 sidenav">
                  <p><img src="https://vignette.wikia.nocookie.net/supermarioglitchy4/images/c/c7/Kirby_render_for_ssb.jpg/revision/latest?cb=20140505220653" style="height:auto" width=100%/></p>
                </div>
                <div class="col-sm-9 sidenav">
                    <p class="blog">Este ser solía estar encargado de la administración de redes y la programación de los routers y switches
                    necesarios para el funcionamiento de las topologías establecidas para el funcionamiento del proyecto. Sin embargo, fue
                    trasladado a interfaz de usuario. Sí, él es el encargado de que estés viendo estas idioteces. En su defensa, los demás
                    miembros del equipo no enviaron sus fotos reales, por lo que le fue imposible crear una página seria.</p>
                </div>
              </div>
            </div>
          </div>
  </div>
</div>
</body>
</html>

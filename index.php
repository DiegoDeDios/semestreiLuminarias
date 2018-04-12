<html>
<head>

  <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>
  <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js'></script>
  <script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>
  <script src='ajax-search.js'></script>

  <meta charset="utf-8">
  <title>AlumbraTec</title>


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
<?php 
if ($_SERVER['REQUEST_METHOD'] == 'POST'){ 
    if (isset($_POST['login'])) { //user logging in

        require 'login.php';
        
    }
 }
?>
  <div class="Menu">
    <div class="col-sm-12">  <!-- Contenedor del navbar -->
      <nav class= "navbar navbar-inverse">
        <div class= "container-fluid">
          <div class="navbar-header">
              <a data-toggle="tab" class="navbar-brand" href="#home" href="#">Home</a>
          </div>
          <ul class="nav navbar-nav">
            <li><a data-toggle="tab" href="#au" href = "#">Sobre Nosotros</a></li>
          </ul>
          <ul class ="nav navbar-nav navbar-right">
            <li><a href="#" class="btn btn-primary btn-lg" role="button" data-toggle="modal" data-target="#login-modal">Inicio de sesión</a></li>
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

        <!--En esta version del index no existen las petañas de busqueda y edicion de tablas-->

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

          <!--login trial-->

          <!-- BEGIN # MODAL LOGIN -->
          <div class="modal fade" id="login-modal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true" style="display: none;">
            <div class="modal-dialog">
        			<div class="modal-content">
        				<div class="modal-header" align="center">
        					<img class="img-circle" id="img_logo" src="http://bootsnipp.com/img/logo.jpg">
        					<button type="button" class="close" data-dismiss="modal" aria-label="Close">
        						<span class="glyphicon glyphicon-remove" aria-hidden="true"></span>
        					</button>
        				</div>

                <!-- Begin # DIV Form -->

                <div id="div-forms">

                              <!-- Begin # Login Form -->
                  <form id="login-form" action="login.php" method="post">
                    <div class="modal-body">
      		            <div id="div-login-msg">
                          <div id="icon-login-msg" class="glyphicon glyphicon-chevron-right"></div>
                          <span id="text-login-msg">Introduzca su usuario y contraseña.</span>
                      </div>

          		    		<input id="login_username" class="form-control" type="text" name="email"  placeholder="Correo" required>
          		    		<input id="login_password" class="form-control" type="password" name= "password" placeholder="Contraseña" required>

                      <div class="checkbox">
                        <label>
                          <input type="checkbox"> Recordar cuenta
                        </label>
                      </div>
        		    	  </div>
        		        <div class="modal-footer">
                      <div>
                        <button type="submit" class="btn btn-primary btn-lg btn-block" name="login">Iniciar sesión</button>
                      </div>
        		    	    <div>
                        <button id="login_lost_btn" type="button" class="btn btn-link">Olvidaste tu contraseña?</button>
                      </div>
        		        </div>
                  </form>
                                <!-- End # Login Form -->

                                <!-- Begin | Lost Password Form -->
                  <form id="lost-form" style="display:none;">
            		    <div class="modal-body">
              				<div id="div-lost-msg">
                        <div id="icon-lost-msg" class="glyphicon glyphicon-chevron-right"></div>
                        <span id="text-lost-msg">Por favor escribe tu e-mail.</span>
                      </div>
              				<input id="lost_email" class="form-control" type="text" placeholder="E-Mail (type ERROR for error effect)" required>
              			</div>
          		      <div class="modal-footer">
                      <div>
                        <button type="submit" class="btn btn-primary btn-lg btn-block">Enviar</button>
                      </div>
                      <div>
                        <button id="lost_login_btn" type="button" class="btn btn-link">Iniciar sesión</button>
                      </div>
          		      </div>
                  </form>
                              <!-- End | Lost Password Form -->

                </div>
                          <!-- End # DIV Form -->

        			</div>
        		</div>
        	</div>

            <!--Final del login en caso de no funcionar-->
    </div>

    <script>
    $(function() {

        var $formLogin = $('#login-form');
        var $formLost = $('#lost-form');
        var $formRegister = $('#register-form');
        var $divForms = $('#div-forms');
        var $modalAnimateTime = 300;
        var $msgAnimateTime = 150;
        var $msgShowTime = 2000;

        $("form").submit(function (){
        });

        $('#login_lost_btn').click( function () { modalAnimate($formLogin, $formLost); });
        $('#lost_login_btn').click( function () { modalAnimate($formLost, $formLogin); });

        function modalAnimate ($oldForm, $newForm) {
            var $oldH = $oldForm.height();
            var $newH = $newForm.height();
            $divForms.css("height",$oldH);
            $oldForm.fadeToggle($modalAnimateTime, function(){
                $divForms.animate({height: $newH}, $modalAnimateTime, function(){
                    $newForm.fadeToggle($modalAnimateTime);
                });
            });
        }

        function msgFade ($msgId, $msgText) {
            $msgId.fadeOut($msgAnimateTime, function() {
                $(this).text($msgText).fadeIn($msgAnimateTime);
            });
        }

        function msgChange($divTag, $iconTag, $textTag, $divClass, $iconClass, $msgText) {
            var $msgOld = $divTag.text();
            msgFade($textTag, $msgText);
            $divTag.addClass($divClass);
            $iconTag.removeClass("glyphicon-chevron-right");
            $iconTag.addClass($iconClass + " " + $divClass);
            setTimeout(function() {
                msgFade($textTag, $msgOld);
                $divTag.removeClass($divClass);
                $iconTag.addClass("glyphicon-chevron-right");
                $iconTag.removeClass($iconClass + " " + $divClass);
      		}, $msgShowTime);
        }
    });
    </script>

    <style>
      @import url(http://fonts.googleapis.com/css?family=Roboto);

      * {
          font-family: 'Roboto', sans-serif;
      }

      #login-modal .modal-dialog {
          width: 350px;
      }

      #login-modal input[type=text], input[type=password] {
      	margin-top: 10px;
      }

      #div-login-msg,
      #div-lost-msg,
      #div-register-msg {
          border: 1px solid #dadfe1;
          height: 30px;
          line-height: 28px;
          transition: all ease-in-out 500ms;
      }

      #div-login-msg.success,
      #div-lost-msg.success,
      #div-register-msg.success {
          border: 1px solid #68c3a3;
          background-color: #c8f7c5;
      }

      #div-login-msg.error,
      #div-lost-msg.error,
      #div-register-msg.error {
          border: 1px solid #eb575b;
          background-color: #ffcad1;
      }

      #icon-login-msg,
      #icon-lost-msg,
      #icon-register-msg {
          width: 30px;
          float: left;
          line-height: 28px;
          text-align: center;
          background-color: #dadfe1;
          margin-right: 5px;
          transition: all ease-in-out 500ms;
      }

      #icon-login-msg.success,
      #icon-lost-msg.success,
      #icon-register-msg.success {
          background-color: #68c3a3 !important;
      }

      #icon-login-msg.error,
      #icon-lost-msg.error,
      #icon-register-msg.error {
          background-color: #eb575b !important;
      }

      #img_logo {
          max-height: 100px;
          max-width: 100px;
      }

      /* #########################################
         #    override the bootstrap configs     #
         ######################################### */

      .modal-backdrop.in {
          filter: alpha(opacity=50);
          opacity: .8;
      }

      .modal-content {
          background-color: #ececec;
          border: 1px solid #bdc3c7;
          border-radius: 0px;
          outline: 0;
      }

      .modal-header {
          min-height: 16.43px;
          padding: 15px 15px 15px 15px;
          border-bottom: 0px;
      }

      .modal-body {
          position: relative;
          padding: 5px 15px 5px 15px;
      }

      .modal-footer {
          padding: 15px 15px 15px 15px;
          text-align: left;
          border-top: 0px;
      }

      .checkbox {
          margin-bottom: 0px;
      }

      .btn {
          border-radius: 0px;
      }

      .btn:focus,
      .btn:active:focus,
      .btn.active:focus,
      .btn.focus,
      .btn:active.focus,
      .btn.active.focus {
          outline: none;
      }

      .btn-lg, .btn-group-lg>.btn {
          border-radius: 0px;
      }

      .btn-link {
          padding: 5px 10px 0px 0px;
          color: #95a5a6;
      }

      .btn-link:hover, .btn-link:focus {
          color: #2c3e50;
          text-decoration: none;
      }

      .glyphicon {
          top: 0px;
      }

      .form-control {
        border-radius: 0px;
      }
    </style>
</body>
</html>
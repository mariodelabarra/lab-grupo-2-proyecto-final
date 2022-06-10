# Hola programador de HaC Pedidos👋🏾 👩🏾‍💻

En este archivo estaran las instrucciones e informacion necesaria para poder ejecutar el proyecto sin problemas y poder colaborar con el mismo utilizando las herramientas requeridas.

Los programas que vas a necesitar instalar son los siguientes:
<ul>
  <li>CodeBlocks v17 (<a href="https://drive.google.com/file/d/1OQaUC8NAtHcUmFgER8cMjyUCqq_a1z50/view">Descargar CodeBlocks</a>).</li>
  <li>Git (<a href="https://git-scm.com/downloads">Descargar Git</a>).</li>
</ul>

Para la administracion de los features/bugfix/issues utilizaremos Trello, para acceder al tablero haz click al siguiente enlace <a href="https://trello.com/b/22QMWt65/tu-pedido-encguida-proyecto-de-maderama">:calendar: Tablero - Tu pedido enCguida</a>. De esta manera podremos llevar un mejor trackeo de las tareas para cada uno de los involucrados.


# Minitutorial Git

<h3>Clonar</h3>
<p>Como primer paso debes clonar (descargar) el repositorio en tu maquina, la ubicacion del repositorio queda a gusto de cada programador. El repositorio se descargara en una carpeta llamada <strong>lab-grupo-2-proyecto-final</strong>, dentro de esa carpeta tendras todos los archivos.</p>
<p>Para ello deberas posicionarte en la carpeta donde quieres clonar desde la consola de GIT y utilizar el siguiente comando:</p>

<p><code>git clone https://github.com/mariodelabarra/lab-grupo-2-proyecto-final.git</code></p>

Luego de ejecutar este comando podras ver que vas se va a generar la carpeta antes mencionada y ya podras empezar a trabajar sobre el proyecto.

<h3>Branches/Ramas</h3>
<img align="center" src="https://miro.medium.com/max/1400/1*JbVkbGtNh08HreFuEk_n4w.png" alt="Ejemplo de ramas" height="" width=""/>
<p>Uno de los objetivos de utilizar un versionador de codigo es gestionar los cambios en el codigo a traves del mismo a lo largo del tiempo. Para tener una gestion de las ramas tendremos la rama principal (main) donde tendremos el codigo ya finalizado y funcionando en nuestro programa, desde main vamos a comenzar a crear ramas en base al codigo de la misma. Por ejemplo: necesitamos hacer el ABM de alguna entidad entonces nos posicionamos en main y utilizamos el/los comandos para crear una rama y switchear a la nueva para poder crear esa nueva funcionalidad.</p>
<p>En lo posible trataremos de seguir la siguiente <strong>nomenclatura</strong> al momento de crear nuevas ramas donde podremos hacer los cambios que vayamos a hacer sobre nuestro proyecto de esta manera podremos saber de que trataria dicho cambio u objetivo del mismo.</p>

<ul>
  <li>:blue_book: <strong>Features</strong> (funcionalidades nuevas en nuestro proyecto): <code>feature/(numero)(nombre-de-la-tarea)</code></li>
  <li>:bug: <strong>Bugfixes/Issues</strong> (errores en el codigo o programa): <code>bugfix/(numero)(nombre-de-la-tarea)</code></li>
</ul>

<p>¿Como podemos crear nuevos branches? ¿Como le indicamos al versionador que queremos cambiarnos a esa rama para poder hacer nuestros cambios? Lo podremos hacer con los siguientes comandos:</p>
<ul>
  <li>Para crear una nueva rama en base a la rama en la que estas posicionado: <code>git branch "nombredebranch"</code></li>
  <li>Para crear una rama nueva y moverse hacia la rama estamos por crear: <code>git checkout -b "nombredebranch"</code></li>  
</ul>

<p><strong>NOTA:</strong> ten en cuenta que primero debes posicionarte en la rama que deseas para luego crear una rama en base al codigo que se encuentra ahí.</p>

<h3>Status/Commit/Push</h3>
<p>Una vez que nuestro nuevo codigo se encuentra funcionando en nuestra rama, deberemos subir los cambios hacia el repositorio remoto (Github) para luego poder hacer un merge (combinar) de nuestros con el codigo de la rama main. Deberemos seguir los siguientes pasos:</p>

<ol>
  <li><code>git status</code> utilizaremos este comando para ver cuales son los cambios que tenemos local en nuestra rama y que queremos subir al repositorio remoto. Debemos revisar que estos cambios sean correctos.</li>
  <li><code>git add .</code> una vez que tenemos los cambios que vamos a subir utilizamos este comando para decirle a GIT los cambios que están en la rama queremos que los incluya para luego poder subirlos, este comando incluira todos los cambios que se hayan hecho sobre la carpeta del repositorio. Una vez utilizado este comando este codigo pasará al <strong>Stage</strong>, en este momento GIT ya conoce cuales seran los cambios que pretendemos subir. Si utilizamos de nuevo el comando de <code>git status</code> podremos ver que los archivos que estan en Stage ahora van a estar en color verde.</li>
  <li><code>git commit -m "mensaje"</code> GIT nos pedirá que dejemos un mensaje para recordar los cambios que hicimos y para ello utilizamos este comando. Además nos ayuda a mover archivos de Staged a Tracked. Esta es una ocasión especial, los archivos han sido guardados o actualizados en el repositorio</li>
  <li><code>git push origin "nombreDeNuestraRama"</code> una vez que ya utilizamos los comandos anteriores ya podremos decirle a GIT que suba los cambios al repositorio remoto (Github), luego deberemos crear el pull request así de esa manera luego podremos hacer un merge de nuestros cambios hacia main.</li>
</ol>



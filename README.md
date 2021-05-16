# C-Plus-Plus-Algorithm-Example
Repositorio para re-aprender C y C++


<h1 align="center">Reaprender C y C++</h1>

<h1 align="center">
  <img src="https://github.com/Ing-Brayan-Martinez/Java-Algorithm-Example/blob/master/assest/spring-ecosystem-750x410.jpg" alt="SpringBoot" width="800"/>
</h1>

[![Build Status](https://travis-ci.org/leerob/dart-react-todo.svg?branch=master)](https://travis-ci.org/leerob/dart-react-todo)
[![codecov](https://codecov.io/gh/leerob/dart-react-todo/branch/master/graph/badge.svg)](https://codecov.io/gh/leerob/dart-react-todo)
[![Strong Mode Compliant](https://img.shields.io/badge/strong_mode-on-brightgreen.svg)](https://github.com/leerob/dart-react-todo/blob/master/analysis_options.yaml#L2)

### Introduccion

En estos tiempos el uso de plataformas basadas en cloud es tan popular, es por eso que necesario crear soluciones adptadas 
ha este tipo de paradigmas. Hay un millón de formas diferentes de crear una aplicación web en el paisaje actual. Diferentes 
idiomas y frameworks van y vienen y varían en popularidad. El objetivo de este documento es informarle sobre el uso de Spring 
Framework para crea plataformas basadas en micro-servicios, usando el patron de arquitectura hexagonal. En este repo se
encuentra una aplicacion echa con spring framework planteada con el patron de arquitectura hexagonal y con integracion para
enviar correos electronicos y con el sistema de colas RabbitMQ.

### Tabla de Contenidos

- [Que es Java?](#que-es-java)
- [Que es Spring?](#que-es-spring)
- [Que es la arquitectura hexagonal?](#que-es-la-arquitectura-hexagonal)
- [Referencias](#referencias)

### Que es Java?

Java es un lenguaje de programación y una plataforma informática que fue comercializada por primera vez en 1995 por
Sun Microsystems. Hay muchas aplicaciones y sitios web que no funcionarán, probablemente, a menos que tengan Java instalado 
y cada día se crean más. Java es rápido, seguro y fiable. Desde ordenadores portátiles hasta centros de datos, desde consolas 
para juegos hasta computadoras avanzadas, desde teléfonos móviles hasta Internet, Java está en todas partes, si es ejecutado
en una plataforma no tiene que ser recompilado para correr en otra. Java es, a partir de 2012, uno de los lenguajes de
programación más populares en uso, particularmente para aplicaciones de cliente-servidor de web, con unos diez millones de
usuarios reportados.2​3​

El lenguaje de programación Java fue desarrollado originalmente por James Gosling, de Sun Microsystems (constituida en 1983 
y posteriormente adquirida el 27 de enero de 2010 por la compañía Oracle),4​ y publicado en 1995 como un componente 
fundamental de la plataforma Java de Sun Microsystems. Su sintaxis deriva en gran medida de C y C++, pero tiene menos 
utilidades de bajo nivel que cualquiera de ellos. Las aplicaciones de Java son compiladas a bytecode (clase Java), que
puede ejecutarse en cualquier máquina virtual Java (JVM) sin importar la arquitectura de la computadora subyacente.

### Que es Spring?

Spring es un framework alternativo al stack de tecnologías estándar en aplicaciones JavaEE. Nació en una época en la que las
tecnologías estándar JavaEE y la visión "oficial" de lo que debía ser una aplicación Java Enterprise tenían todavía muchas
aristas por pulir. Los servidores de aplicaciones eran monstruosos devoradores de recursos y los EJB eran pesados, inflexibles
y era demasiado complejo trabajar con ellos. En ese contexto, Spring popularizó ideas como la inyección de dependencias o el
uso de objetos convencionales (POJOs) como objetos de negocio, que suponían un soplo de aire fresco. Estas ideas permitían un
desarrollo más sencillo y rápido y unas aplicaciones más ligeras. Eso posibilitó que de ser un framework inicialmente diseñado
para la capa de negocio pasara a ser un completo stack de tecnologías para todas las capas de la aplicación.

Las ideas "innovadoras" que en su día popularizó Spring se han incorporado en la actualidad a las tecnologías y herramientas
estándar. Así, ahora mismo no hay una gran diferencia entre el desarrollo con Spring y el desarrollo JavaEE "estándar", o al
menos no tanta como hubo en su día. No obstante, Spring ha logrado aglutinar una importante comunidad de desarrolladores en
torno a sus tecnologías y hoy por hoy sigue constituyendo una importante alternativa al estándar que merece la pena conocer.
En la actualidad, las aportaciones más novedosas de Spring se centran en los campos de Big Data/NoSQL, HTML5/móviles y
aplicaciones sociales.

### Que es la arquitectura hexagonal?

La arquitectura hexagonal es un estilo de arquitectura que mueve el foco de un programador desde un plano más conceptual hacia
la distinción entre el interior y el exterior del software. La parte interior son los casos prácticos y el modelo domain está
construido sobre ello. La parte exterior es UI, base de datos, mensajería, etc. La conexión entre el interior y el exterior es
mediante puertos, y su implementación equivalente se conocen como adaptadores. Por esta razón, este estilo de arquitectura se
conoce habitualmente como Puertos y Adaptadores.

La arquitectura hexagonal promueve la separación de asuntos mediante la encapsulación de la lógica en diferentes capas de la
aplicación. Esto permite un aislamiento de mayor nivel, testabilidad, y control sobre el código de negocio específico. Cada capa
de la aplicación tiene un estricto grupo de responsabilidades y requerimientos. Esto crea separaciones más claras entre la lógica
y la funcionalidad, y como esas capas deberían interactuar entre ellas.

Cada parte del hexágono representa un input – puerto, por ejemplo HTTP, que utiliza un adaptador para un tipo específico. Crea 
una separación clara entre el modelo domain y los dispositivos utilizados para las entradas o salidas.

### Referencias

- [Que es Java?](https://es.wikipedia.org/wiki/Java_(lenguaje_de_programaci%C3%B3n))
- [Que es Spring?](http://www.jtech.ua.es/j2ee/publico/spring-2012-13/sesion01-apuntes.html)
- [Que es la arquitectura hexagonal?](https://apiumhub.com/es/tech-blog-barcelona/arquitectura-hexagonal/)
- [Arquitectura hexagonal](https://codely.tv/screencasts/arquitectura-hexagonal-ddd/)

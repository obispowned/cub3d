# Cub3D - Motor Gráfico Falso 3D en C

Este proyecto es un **motor gráfico en un falso 3D**, escrito en **C**.  
Utiliza la técnica de **raycasting**, inspirada en el clásico _Wolfenstein 3D_.  

Desarrollado como parte del currículo de la escuela **42 Madrid**, el objetivo es profundizar en la programación en C, la gestión de memoria y el desarrollo de gráficos.

Más info: [42 Cub3D Docs](https://harm-smits.github.io/42docs/projects/cub3d)

---

## 🧩 Características principales

- **Raycasting en 3D**  
  Renderizado de paredes y objetos con perspectiva usando la técnica de raycasting.

- **Interacción con el entorno**  
  Capacidad para abrir y cerrar puertas dentro del juego.

---

## 🎮 Controles básicos

| Tecla     | Acción                |
| --------- | --------------------- |
| W, A, S, D| Mover al jugador      |
| ←, →      | Rotar la vista        |
| SHIFT     | Correr                |
| ESC       | Salir del juego       |

---

## 🗺️ Mapas personalizables

Puedes crear mapas en formato `.cub` con especificaciones para texturas y colores.  
El mapa debe respetar el siguiente formato para ser válido:

    NO textures/norte.xpm
    SO textures/sur.xpm
    EA textures/este.xpm
    WE textures/oeste.xpm
    F 255,255,255
    C 0,0,0

    111111111111111
    100000000000001
    101110111110101
    100010000010001
    111111111111111

## 📥 Instalación y Ejecución
Clonar el repositorio:
git clone https://github.com/obispowned/cub3d.git
cd cub3d

Compilar el proyecto:
make

Ejecutar el juego con un mapa:
./cub3d maps/map0.cub

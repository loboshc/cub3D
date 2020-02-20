

int        main()
{
    void *mlx_ptr;
    void *win_ptr; 
    
    int w; // width

    // posiciones inciales
    posX = 22.0;
    posY = 11.5;
    dirX = -1;
    dirY = 0;
    planoX = 0.0;
    planoY = 0.66;

    mlx_ptr = mlx_init(); // para iniciar 
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "CUB3D"); // para crear la pantalla con el tamaño deseado y el titulo 
    mlx_string_put(mlx_ptr, win_ptr, 200,240, 0xFF0000, "Lets go!"); // para poner una frase en pantalla
    mlx_loop(mlx_ptr); // para manejar los eventos de teclado y raton 



    return (0);
    //para comimpilar
    //-lmlx -framework OpenGL -framework AppKit
}


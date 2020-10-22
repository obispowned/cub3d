void	ft_compr(mapa, pos)
{
	pos = mapa[x][y];
	if (mapa[x+1][y] == 0)
	{
		mapa[x+1][y] = 3;
		ft_compr(mapa, pos)
	}
	else if (3)
		ignora
	else
	{
		error ();
		exit ()
	}
	if (mapa[x][y+1] == 0)
	{
		mapa[x][y+1] = 3;
		ft_compr(mapa,pos);
	}

}

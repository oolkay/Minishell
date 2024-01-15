/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_banner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omer/baha <oolkay/acepni@gtu.xv6>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:14:15 by omer/baha         #+#    #+#             */
/*   Updated: 2023/07/27 00:14:15 by omer/baha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_banner1(void)
{
	ft_putstr_fd("   ░█─░█ ░█▄▄█ ░█▄▄▄ ░█─── ░█──▀█ ▄█▄\n\n", 1);
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd("              █████████  ███████████ █████  █████    ██", 1);
	ft_putstr_fd("███ █████ █████   █████  ████████ \n", 1);
	ft_putstr_fd("             ███░░░░░███░█░░░███░░░█░░███  ░░███    ░░█", 1);
	ft_putstr_fd("██ ░░███ ░░███   ░░███  ███░░░░███\n", 1);
	ft_putstr_fd("            ███     ░░░ ░   ░███  ░  ░███   ░███     ░░", 1);
	ft_putstr_fd("███ ███   ░███    ░███ ░███   ░░░ \n", 1);
	ft_putstr_fd(DEFAULT, 1);
	ft_putstr_fd("           ░███             ░███     ░███   ░███      ░", 1);
	ft_putstr_fd("░█████    ░███    ░███ ░█████████ \n", 1);
	ft_putstr_fd("           ░███    █████    ░███     ░███   ░███       ", 1);
	ft_putstr_fd("███░███   ░░███   ███  ░███░░░░███\n", 1);
	ft_putstr_fd("           ░░███  ░░███     ░███     ░███   ░███      █", 1);
	ft_putstr_fd("██ ░░███   ░░░█████░   ░███   ░███\n", 1);
	ft_putstr_fd("            ░░█████████     █████    ░░████████      ██", 1);
	ft_putstr_fd("███ █████    ░░███     ░░████████ \n", 1);
	ft_putstr_fd("             ░░░░░░░░░     ░░░░░      ░░░░░░░░      ░░░", 1);
	ft_putstr_fd("░░ ░░░░░      ░░░       ░░░░░░░░  \n", 1);
	ft_putstr_fd(DEFAULT, 1);
}

void	ft_banner(void)
{
	ft_putstr_fd(ORANGE, 1);
	ft_putstr_fd(" ██████   ██████ █████ ██████   █████ █████  █████████ ", 1);
	ft_putstr_fd(" █████   █████ ██████████ █████       █████      \n", 1);
	ft_putstr_fd("░░██████ ██████ ░░███ ░░██████ ░░███ ░░███  ███░░░░░███", 1);
	ft_putstr_fd("░░███   ░░███ ░░███░░░░░█░░███       ░░███       \n", 1);
	ft_putstr_fd(" ░███░█████░███  ░███  ░███░███ ░███  ░███ ░███    ░░░ ", 1);
	ft_putstr_fd(" ░███    ░███  ░███  █ ░  ░███        ░███       \n", 1);
	ft_putstr_fd(" ░███░░███ ░███  ░███  ░███░░███░███  ░███ ░░█████████ ", 1);
	ft_putstr_fd(" ░███████████  ░██████    ░███        ░███       \n", 1);
	ft_putstr_fd(" ░███ ░░░  ░███  ░███  ░███ ░░██████  ░███  ░░░░░░░░███", 1);
	ft_putstr_fd(" ░███░░░░░███  ░███░░█    ░███        ░███       \n", 1);
	ft_putstr_fd(" ░███      ░███  ░███  ░███  ░░█████  ░███  ███    ░███", 1);
	ft_putstr_fd(" ░███    ░███  ░███ ░   █ ░███"GREY"CBOLAT"ORANGE"█ ░██", 1);
	ft_putstr_fd("█"GREY"MKARDES"ORANGE"\n", 1);
	ft_putstr_fd(" █████     █████ █████ █████  ░░█████ █████░░█████████ ", 1);
	ft_putstr_fd(" █████   █████ ██████████ ███████████ ████████████\n", 1);
	ft_putstr_fd("░░░░░     ░░░░░ ░░░░░ ░░░░░    ░░░░░ ░░░░░  ░░░░░░░░░  ", 1);
	ft_putstr_fd("░░░░░   ░░░░░ ░░░░░░░░░░ ░░░░░░░░░░░ ░░░░░░░░░░░ \n\n", 1);
	ft_putstr_fd(WHITE, 1);
	ft_putstr_fd("         ░█▀▀▀█ ░█▀▀▀█ ░█─── ░█─▄▀ ─█▀▀█ ░█──░█──      ", 1);
	ft_putstr_fd("   ─█▀▀█ ░█▀▀█ ░█▀▀▀ ░█▀▀█ ░█▄─░█ ▀█▀\n", 1);
	ft_putstr_fd("         ░█──░█ ░█──░█ ░█─── ░█▀▄─ ░█▄▄█ ░█▄▄▄█     ▀▀ ", 1);
	ft_putstr_fd("   ░█▄▄█ ░█─── ░█▀▀▀ ░█▄▄█ ░█░█░█ ░█─\n", 1);
	ft_putstr_fd("         ░█▄▄▄█ ░█▄▄▄█ ░█▄▄█ ░█─░█ ░█─░█ ──░█── ──     ", 1);
	ft_banner1();
}

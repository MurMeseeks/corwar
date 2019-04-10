/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemiy <artemiy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:36:30 by artemiy           #+#    #+#             */
/*   Updated: 2019/04/10 21:36:56 by artemiy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"
#include "libft.h"

void	vm_init_memory(unsigned char *memory)
{
	unsigned int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		memory[i] = 0;
		i++;
	}
}

void	vm_init_arrays(t_vm *vm)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		vm->lives[i] = 0;
		vm->p_num[i] = 0;
		i++;
	}
}

t_vm	*vm_new(int dump)
{
	t_vm	*vm;

	vm = (t_vm *)malloc(sizeof(t_vm));
	if (!vm)
		exit(2);
	vm->cycles = 0;
	vm->champion = NULL;
	vm->process = NULL;
	vm->cycles_die = CYCLE_TO_DIE;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->cycles_to_dump = dump;
	vm->dump = dump;
	vm->live_exec = 0;
	vm->checkups = 0;
	vm->p_total = 0;
	vm_init_memory(vm->memory);
	vm_init_arrays(vm);
	return (vm);
}

void	vm_dump_memory(unsigned char *memory)
{
	int	i;

	i = -1;
	while (++i < 32)
		ft_printf("%02d ", i + 1);
	ft_printf("\n");
	i = 0;
	while (i < MEM_SIZE)
	{
		if (memory[i])
			ft_printf("\e[32m");
		ft_printf("%02hhx ", memory[i]);
		if (memory[i])
			ft_printf("\e[39m");
		if ((i + 1) % 32 == 0 && i)
			ft_printf("\n");
		i++;
	}
	ft_printf("\n");
	exit(0);
}

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    norm.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 02:59:16 by jodufour          #+#    #+#              #
#    Updated: 2021/11/15 23:54:14 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

norm:
	@norminette ${SRC_DIR} ${PRV_DIR} ${INC_DIR} | grep 'Error' ; true

.PHONY:	norm

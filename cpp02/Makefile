NAME = war

CXX = c++ -fsanitize=address -ggdb
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS_FOLDER = objs
VPATH = srcs/
RM = rm -rf

SRCS =	main.cpp Warlock.cpp ASpell.cpp ATarget.cpp Dummy.cpp Fwoosh.cpp Fireball.cpp \
		Polymorph.cpp BrickWall.cpp SpellBook.cpp TargetGenerator.cpp
OBJS = ${SRCS:%.cpp=${OBJS_FOLDER}/%.o}

${NAME}:	${OBJS_FOLDER} ${OBJS}
			${CXX} ${OBJS} -o ${NAME}

${OBJS_FOLDER}:
			mkdir -p objs

${OBJS_FOLDER}/%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS_FOLDER}

fclean: 	clean
			${RM} ${NAME}

all : 		${NAME}

re: 		fclean all

.PHONY: 	fclean clean all re

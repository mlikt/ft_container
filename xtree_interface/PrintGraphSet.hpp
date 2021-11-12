#ifndef __PGS__
#define __PGS__

#define BLACK  "\033[22;2m"
#define YELLOW    "\033[22;33m"
#define RED  "\033[22;31m"
#define GREEN "\e[0;32m"
#define BLUE  "\033[40;34m"
#define RESETCOLOR "\033[0m"

#define ON      1
#define OFF     0
namespace ft {
template <class tree_traits>
void xtree<tree_traits>::PrintGraphSet()
{
        if (this->Root == NIL)
        {
                return;
        }

        if (this->Root->colour == Paint::Red) {
                 std::cout << RED << Root->Value << RESETCOLOR << std::endl;
         } else {
                 std::cout << BLACK << Root->Value << RESETCOLOR << std::endl;
         }
        PrintSubtreeSet(this->Root, "", OFF);
        std::cout << std::endl;
}

template <class tree_traits>
void xtree<tree_traits>::PrintSubtreeSet(nodeptr Root, const std::string& prefix, bool tumbler)
{
        if (Root == NIL)
        {
                return;
        }
        bool hasLeft; 
        bool hasRight;
        
        if (tumbler) {
                hasLeft = (Left(Root) != NULL); // NIL - если не хочешь отображать листья
                hasRight = (Right(Root) != NULL);
        } else {
                hasLeft = (Left(Root) != NIL); // NIL - если не хочешь отображать листья
                hasRight = (Right(Root) != NIL);
        }

        if (!hasLeft && !hasRight)
        {
                return;
        }

        std::cout << GREEN << prefix << RESETCOLOR << std::flush;
        std::cout << BLUE << ((hasLeft  && hasRight) ? "├── " : "") << RESETCOLOR << std::flush;
        std::cout << BLUE <<  ((!hasLeft && hasRight) ? "└── " : "") << RESETCOLOR << std::flush;

        if (hasRight)
        {
                bool printStrand = (hasLeft && hasRight && (Right(Root)->Right != NULL || Right(Root)->Left != NULL));
                std::string newPrefix = prefix + (printStrand ? "│   " : "    ");
                if (Right(Root) == NIL){
                        std::cout << BLACK << "NIL" << RESETCOLOR << std::endl;
                } else if (Right(Root)->colour == Paint::Red) {
                        std::cout << RED << Right(Root)->Value << RESETCOLOR << std::endl;
                } else {
                        std::cout << BLACK << Right(Root)->Value << RESETCOLOR << std::endl;
                }
                PrintSubtreeSet(Right(Root), newPrefix, tumbler);
        }

        if (hasLeft)
        {
                std::cout << GREEN << (hasRight ? prefix : "") << "└── " << RESETCOLOR;
                if (Left(Root) == NIL){
                        std::cout << BLACK << "NIL" << RESETCOLOR << std::endl;
                }
                else if (Left(Root)->colour == Paint::Red) {
                        std::cout << RED << Left(Root)->Value << RESETCOLOR << std::endl;
                } else {
                        std::cout << BLACK << Left(Root)->Value << RESETCOLOR << std::endl;
                }
                PrintSubtreeSet(Left(Root), prefix + "    ", tumbler);
        }
}
}
#endif
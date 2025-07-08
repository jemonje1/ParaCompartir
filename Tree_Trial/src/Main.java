import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Tree<Character> arbol = new Tree<>();

        // Primera inserción - cuando el árbol está vacío
        arbol.add(arbol.getRoot(),'h' );

        // Siguientes inserciones
        arbol.add(arbol.getRoot(), 'c');
        arbol.add(arbol.getRoot(), 'r');
        arbol.add(arbol.getRoot(), 'o');
        arbol.add(arbol.getRoot(), 's');
        arbol.add(arbol.getRoot(), 'a');

        System.out.println("Árbol por niveles (formato completo):");
        arbol.printTreeLevels();

        System.out.println("\nÁrbol por niveles (formato simple):");
        arbol.printTreeSimple();
    }
}
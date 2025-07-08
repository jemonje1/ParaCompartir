import java.util.Queue;
import java.util.LinkedList;
import java.util.List;
import java.util.ArrayList;

public class Tree <T extends Comparable<T>>{
    private Node<T> root;

    public boolean isEmpty() {
        return root == null;
    }

    public Node<T> getRoot() {
        return root;
    }

    public boolean isRoot(Node<T> node) {
        return root==node;
    }

    public boolean isLeaf(Node<T> node) {
        return node.getLeft()==null && node.getRight()==null;
    }

    public boolean isInternal(Node<T> node) {
        return !isLeaf(node) && !isRoot(node);
    }

    public Node<T> add(Node<T> node, T value) {
        //Cuando no hay nada, el arbol creará la raiz con el nodo a insertar
        if(root == null) {
            root = new Node<>(value);
            return root;
        }
        //Para recursión, crea un nodo hasta que la posición esté totalmente vacía
        if(node == null) {
            return new Node<>(value);
        }
        //Primera condicion, comparamos el valor del nodo actual con el anterior
        //Si el nodo actual es mayor que el valor a inserta
        if(node.getElement().compareTo(value) > 0) {
            //El nuevo nodo va al arbol izquierdo si es menor
            if(node.getLeft() == null) {
                //Si no hay hijo izquierdo, este se creará en este método para el nodo actual
                Node<T> left = new Node<>(value);
                left.setRoot(node); //Setear el padre del hijo
                node.setLeft(left); //Setear el hijo del padre
            }else {
                //Si ya existe el izquierdo se hace el mismo método hasta que encuentre un vacío
                add(node.getLeft(), value);
            }
        } else {
            //Si el valor es mayor, debe ir a la derecha (o si es igual)
            if(node.getRight() == null) {
                //Si no hay un hiojo derecho se le creará un hijo al nodo actual
                Node<T> right = new Node<>(value);
                right.setRoot(node);
                node.setRight(right);
            } else {
                //Si ya hay hijo derecho, se continuará recursivamente hasta encontrar un vacio
                add(node.getRight(), value);
            }
        }
        return node;
    }

    // Método principal para imprimir el árbol por niveles
    public void printTreeLevels() {
        if (root == null) {
            System.out.println("El árbol está vacío");
            return;
        }

        // Obtener todos los niveles del árbol
        List<List<String>> levels = getLevels();

        // Calcular el ancho total necesario para la impresión
        int maxWidth = calculateMaxWidth(levels);

        // Imprimir cada nivel con el espaciado correcto
        for (int i = 0; i < levels.size(); i++) {
            printLevel(levels.get(i), i, levels.size(), maxWidth);
        }
    }

    // Método para obtener todos los elementos organizados por niveles
    private List<List<String>> getLevels() {
        List<List<String>> levels = new ArrayList<>();
        Queue<Node<T>> queue = new LinkedList<>();

        queue.offer(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            List<String> currentLevel = new ArrayList<>();

            // Procesar todos los nodos del nivel actual
            for (int i = 0; i < levelSize; i++) {
                Node<T> current = queue.poll();

                if (current != null) {
                    // Agregar el valor del nodo actual
                    currentLevel.add(current.getElement().toString());

                    // Agregar hijos a la cola (pueden ser null)
                    queue.offer(current.getLeft());
                    queue.offer(current.getRight());
                } else {
                    // Nodo vacío - agregar placeholder
                    currentLevel.add("null");

                    // Agregar null para mantener la estructura
                    queue.offer(null);
                    queue.offer(null);
                }
            }

            // Solo agregar el nivel si tiene al menos un nodo real
            if (hasRealNode(currentLevel)) {
                levels.add(currentLevel);
            } else {
                break; // No hay más nodos reales
            }
        }

        return levels;
    }

    // Verificar si un nivel tiene al menos un nodo real (no null)
    private boolean hasRealNode(List<String> level) {
        for (String node : level) {
            if (!node.equals("null")) {
                return true;
            }
        }
        return false;
    }

    // Calcular el ancho máximo necesario
    private int calculateMaxWidth(List<List<String>> levels) {
        if (levels.isEmpty()) return 0;

        int lastLevelSize = levels.get(levels.size() - 1).size();
        return lastLevelSize * 4; // 4 espacios por elemento aproximadamente
    }

    // Imprimir un nivel específico con el espaciado correcto
    private void printLevel(List<String> level, int levelIndex, int totalLevels, int maxWidth) {
        int spacing = maxWidth / (level.size() + 1);
        int leftPadding = spacing / 2;

        // Imprimir espacios iniciales
        for (int i = 0; i < leftPadding; i++) {
            System.out.print(" ");
        }

        // Imprimir elementos del nivel
        for (int i = 0; i < level.size(); i++) {
            String element = level.get(i);

            if (!element.equals("null")) {
                System.out.print(element);
            } else {
                System.out.print(" "); // Espacio para nodos null
            }

            // Agregar espaciado entre elementos
            if (i < level.size() - 1) {
                for (int j = 0; j < spacing - element.length(); j++) {
                    System.out.print(" ");
                }
            }
        }

        System.out.println(); // Nueva línea al final del nivel
    }

    // Versión simple para árboles pequeños
    public void printTreeSimple() {
        if (root == null) {
            System.out.println("Árbol vacío");
            return;
        }

        Queue<Node<T>> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();

            // Imprimir todos los nodos del nivel actual
            for (int i = 0; i < levelSize; i++) {
                Node<T> current = queue.poll();

                if (current != null) {
                    System.out.print(current.getElement() + " ");

                    // Agregar hijos a la cola
                    if (current.getLeft() != null) queue.offer(current.getLeft());
                    if (current.getRight() != null) queue.offer(current.getRight());
                }
            }

            System.out.println(); // Nueva línea después de cada nivel
        }
    }
}


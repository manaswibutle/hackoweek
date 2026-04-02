include <stdio.h>
#include <string.h>

#define MAX 100
#define URL_LEN 100

typedef struct {
    char urls[MAX][URL_LEN];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Push
void push(Stack *s, const char *url) {
    if (s->top < MAX - 1) {
        strcpy(s->urls[++(s->top)], url);
    }
}

// Pop
char* pop(Stack *s) {
    if (s->top == -1) return NULL;
    return s->urls[(s->top)--];
}

// Peek
char* peek(Stack *s) {
    if (s->top == -1) return NULL;
    return s->urls[s->top];
}

// Clear stack
void clear(Stack *s) {
    s->top = -1;
}

// Browser history
typedef struct {
    Stack back;
    Stack forward;
} Browser;

void visit(Browser *b, const char *url) {
    char *current = peek(&b->back);
    if (current) push(&b->back, current);  // keep current page
    push(&b->back, url);
    clear(&b->forward);
}

void back(Browser *b) {
    if (b->back.top <= 0) {
        printf("No page to go back.\n");
        return;
    }
    char *current = pop(&b->back);
    push(&b->forward, current);
}

void forward(Browser *b) {
    if (b->forward.top == -1) {
        printf("No page to go forward.\n");
        return;
    }
    char *url = pop(&b->forward);
    push(&b->back, url);
}

void currentPage(Browser *b) {
    char *page = peek(&b->back);
    if (page) printf("Current page: %s\n", page);
    else printf("No page visited.\n");
}

int main() {
    Browser browser;
    init(&browser.back);
    init(&browser.forward);

    visit(&browser, "https://example.com");
    visit(&browser, "https://openai.com");
    visit(&browser, "https://stackoverflow.com");

    currentPage(&browser); // Should print StackOverflow

    back(&browser);
    currentPage(&browser); // OpenAI

    back(&browser);
    currentPage(&browser); // Example

    forward(&browser);
    currentPage(&browser); // OpenAI

    return 0;
}

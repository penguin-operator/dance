use ncurses::{
    endwin,
    getch,
    getmaxyx,
    initscr,
    nodelay,
    noecho,
    refresh,
    stdscr,
    curs_set,
    CURSOR_VISIBILITY
};

pub mod tabs;
pub mod view;
pub mod utils;

pub use tabs::{TAB, EDITOR, EXPLORER};
pub use view::VIEW;

fn main() {
    initscr();
    nodelay(stdscr(), true);
    noecho();
    curs_set(CURSOR_VISIBILITY::CURSOR_INVISIBLE);

    let (mut h, mut w) = (0, 0);
    getmaxyx(stdscr(), &mut h, &mut w);

    let mut views = vec![
        VIEW::new((0, 0), (h, w/2)),
        VIEW::new((0, w/2), (h, w/2)),
    ];

    views[0].addtab(EDITOR::new());
    views[1].addtab(EXPLORER::new());

    loop {
        for view in &mut views {
            view.refresh();
        }
        refresh();
        if getch() == 'q' as i32 {
            break;
        }
    }
    endwin();
}

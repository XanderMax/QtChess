import QtQuick 2.0
import QtGraphicalEffects 1.0

Item
{
    Image
    {
        id: pieceImage

        source: ""

        anchors.fill: parent
        anchors.centerIn: parent
    }

//    DropShadow {
//            anchors.fill: pieceImage
//            horizontalOffset: 7
//            verticalOffset: 7
//            radius: 8.0
//            samples: 17
//            color: "#80000000"
//            source: pieceImage
//        }


    states:
    [
        State{name:"none"; PropertyChanges{target: pieceImage; source:""}},

        State{name:"w_pawn"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/pawn_white.svg"}},
        State{name:"b_pawn"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/pawn_black.svg"}},

        State{name:"w_knight"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/knight_white.svg"}},
        State{name:"b_knight"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/knight_black.svg"}},

        State{name:"w_bishop"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/bishop_white.svg"}},
        State{name:"b_bishop"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/bishop_black.svg"}},

        State{name:"w_rook"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/rook_white.svg"}},
        State{name:"b_rook"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/rook_black.svg"}},

        State{name:"w_queen"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/queen_white.svg"}},
        State{name:"b_queen"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/queen_black.svg"}},

        State{name:"w_king"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/king_white.svg"}},
        State{name:"b_king"; PropertyChanges{target: pieceImage; source:"qrc:/imgs/king_black.svg"}}
    ]

}

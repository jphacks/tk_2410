import type React from "react";
import Sentence from "./Sentence";
import SvgButton from "./SvgButton";

interface CardProps {
  date: string;
  image: string;
  text: string;
  // children: ReactNode;
}

const Card: React.FC<CardProps> = ({ date, image, text }) => {
  return (
    <div className="card">
      <img src={image} aria-label="本の表紙（仮）" />
      <h2>{date}</h2>
      <Sentence text={text} />
      <div className="svg-button-wrapper">
        <SvgButton />
        {/* {children} */}
      </div>
    </div>
  );
};

export default Card;

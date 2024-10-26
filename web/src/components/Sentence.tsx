import React from "react";
import kakko from "../assets/kakko.png";
import "./Sentence.css";

interface CardProps {
  text: string;
}

const Sentence: React.FC<CardProps> = ({ text }) => {
  return (
    <div className="sentence">
      <img className="left-quote" src={kakko} alt="quote left" />
      <p className="text-content">{text}</p>
      <img className="right-quote" src={kakko} alt="quote right" />
    </div>
  );
};

export default Sentence;

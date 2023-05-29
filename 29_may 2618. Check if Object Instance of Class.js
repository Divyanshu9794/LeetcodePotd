/**
 * @param {any} object
 * @param {any} classFunction
 * @return {boolean}
 */

const checkIfInstanceOf = (obj, classFunction) => {
  
  if (obj===null || obj===undefined || typeof classFunction !== 'function') {
    return false; 
  }

  let prototype = Object.getPrototypeOf(obj); 
  while (prototype) {
      if (prototype === classFunction.prototype) {
     
      return true;
    }
    prototype = Object.getPrototypeOf(prototype); 
  }
  return false; 
};
